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
  | Start;



let component = ReasonReact.reducerComponent("Board");

let make = (~width: int, ~height: int, ~mines: int, _children) => {
  ...component,
  initialState: () => {gameState: NotPlayed, width, height, mines},
  reducer: (action, state) =>
    switch (action) {
    | Start => ReasonReact.Update({...state, gameState: Playing})
    },
  render: self => {
    let rec createColumn = (columns, colIndex) =>
      colIndex < self.state.width ?
        createColumn(List.append(columns, [<Cell />]), colIndex + 1) :
        columns;
    let rec createRow = (rows, rowIndex) =>
      rowIndex < self.state.height ?
        createRow(List.append(rows, [createColumn([], 0)]), rowIndex + 1) :
        rows;
    let createBoard = () => createRow([], 0);

    <div>
      ...{
           Array.of_list(
             List.map(
               rowCols => <div> ...{Array.of_list(rowCols)} </div>,
               createBoard(),
             ),
           )
         }
    </div>;
  },
};