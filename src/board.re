type gameState =
  | Playing
  | Won
  | Lost
  | NotPlayed;

type state = {
  gameState,
  width: int,
  height: int,
  mines: int,
};

type action =
  | UpdateGameState(gameState);

let component = ReasonReact.reducerComponent("Board");

let make = (~width: int, ~height: int, ~mines: int, _children) => {
  ...component,
  initialState: () => {gameState: NotPlayed, width, height, mines},
  reducer: (action, state) =>
    switch (action) {
    | UpdateGameState(newState) =>
      ReasonReact.Update({...state, gameState: newState})
    },
  render: self => {
    let rec generateMineCoords = coordsList => {
      Random.self_init();
      let row = Random.int(self.state.width);
      let col = Random.int(self.state.height);

      switch (List.exists(pair => pair == [|row, col|], coordsList)) {
      | false => [|row, col|]
      | true => generateMineCoords(coordsList)
      };
    };
    let rec generateRandomMineCoordsList =
            (randomMineCoordList, currentMineCount: int, maxMineCount: int) =>
      switch (currentMineCount < maxMineCount) {
      | false => randomMineCoordList
      | true =>
        generateRandomMineCoordsList(
          List.append(
            randomMineCoordList,
            [generateMineCoords(randomMineCoordList)],
          ),
          currentMineCount + 1,
          maxMineCount,
        )
      };
    let generatedMineCoords =
      generateRandomMineCoordsList([], 0, self.state.mines);
    let onCellReveal: bool => option(int) =
      (isBomb: bool) =>
        isBomb ?
          {
            self.send(UpdateGameState(Lost));
            None;
          } :
          Some(Random.int(6)); /* TODO: Calculate actual neighbor count (# of bombs) */
    let rec createColumn = (columns, colIndex, rowIndex) =>
      colIndex < self.state.width ?
        createColumn(
          List.append(
            columns,
            [
              <Cell
                isMine={
                  List.exists(
                    coord => coord == [|rowIndex, colIndex|],
                    generatedMineCoords,
                  )
                }
                onReveal=onCellReveal
              />,
            ],
          ),
          colIndex + 1,
          rowIndex,
        ) :
        columns;
    let rec createRow = (rows, rowIndex) =>
      rowIndex < self.state.height ?
        createRow(
          List.append(rows, [createColumn([], 0, rowIndex)]),
          rowIndex + 1,
        ) :
        rows;
    let createBoard = () => createRow([], 0);

    <MaterialUi.Grid container=true xs=V12 justify=`Center>
      ...{
           Array.of_list(
             List.map(
               rowCols =>
                 <MaterialUi.Grid
                   item=true container=true xs=V12 justify=`Center>
                   ...{Array.of_list(rowCols)}
                 </MaterialUi.Grid>,
               createBoard(),
             ),
           )
         }
    </MaterialUi.Grid>;
  },
};