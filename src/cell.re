type cellContent =
  | Empty
  | Bomb
  | NeighborCount;

type state = {
  isBomb: bool,
  isRevealed: bool,
  isFlagged: bool,
};

type action =
  | Reveal
  | ToggleFlag;

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

let make = _children => {
  ...component,
  initialState: () => {isBomb: false, isRevealed: false, isFlagged: false},
  reducer: (action, state) =>
    switch (action) {
    | Reveal => ReasonReact.Update({...state, isRevealed: true})
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
                switch (Random.int(4)) {
                | 0 => {js|💣|js} |> ReasonReact.string
                | _ => "" |> ReasonReact.string
                };
              } :
              <button
                className=cellButton
                onClick={
                  _e =>
                    switch (self.state.isBomb) {
                    | false => self.send(Reveal)
                    | true => self.send(Reveal)
                    }
                }
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