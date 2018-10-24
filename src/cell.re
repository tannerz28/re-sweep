type cellContent =
  | Empty
  | Bomb
  | NeighborCount;

type state = {
  isMine: bool,
  isRevealed: bool,
  isFlagged: bool,
  neighborCount: option(int),
};

type action =
  | Reveal
  | ToggleFlag
  | UpdateNeighborCount(int);

let cellClass =
  Css.style([
    Css.width(Css.px(50)),
    Css.height(Css.px(50)),
    Css.important(Css.margin(Css.px(3))),
  ]);

let cellPaper =
  Css.style([
    Css.height(Css.pct(100.0)),
    Css.width(Css.pct(100.0)),
    Css.justifyContent(`center),
    Css.alignItems(`center),
    Css.display(Css.flexBox),
    Css.important(Css.backgroundColor(Css.hex("fcfcfc"))),
  ]);

let cellButton =
  Css.style([Css.width(Css.pct(100.0)), Css.height(Css.pct(100.0))]);

let component = ReasonReact.reducerComponent("Cell");

let make = (~onReveal: bool => option(int), ~isMine: bool, _children) => {
  ...component,
  initialState: () => {
    isMine,
    isRevealed: false,
    isFlagged: false,
    neighborCount: None,
  },
  reducer: (action, state) =>
    switch (action) {
    | Reveal =>
      ReasonReact.UpdateWithSideEffects(
        {...state, isRevealed: true},
        (
          self =>
            switch (onReveal(self.state.isMine)) {
            | Some(int) => self.send(UpdateNeighborCount(int))
            | None => ()
            }
        ),
      )
    | UpdateNeighborCount(count) =>
      ReasonReact.Update({...state, neighborCount: Some(count)})
    | ToggleFlag =>
      ReasonReact.Update({...state, isFlagged: !state.isFlagged})
    },
  render: self =>
    MaterialUi.(
      <Grid item=true className=cellClass>
        <Paper className=cellPaper elevation={`Int(1)} square=true>
          {
            self.state.isRevealed ?
              {
                Random.self_init();
                self.state.isMine ?
                  {js|💣|js} |> ReasonReact.string :
                  (
                    switch (self.state.neighborCount) {
                    | Some(int) => string_of_int(int) |> ReasonReact.string
                    | None => "" |> ReasonReact.string
                    }
                  );
              } :
              <button
                className=cellButton
                onClick={_e => self.send(Reveal)}
                onContextMenu={
                  e => {
                    ReactEvent.Mouse.preventDefault(e);
                    self.send(ToggleFlag);
                  }
                }>
                {
                  self.state.isFlagged ?
                    {js|🚩|js} |> ReasonReact.string :
                    "" |> ReasonReact.string
                }
              </button>
          }
        </Paper>
      </Grid>
    ),
};