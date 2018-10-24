type cellContent =
  | Empty
  | Bomb
  | NeighborCount;

type state = {
  isBomb: bool,
  isRevealed: bool,
};

type action =
  | Reveal;

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

let component = ReasonReact.reducerComponent("Cell");

let make = _children => {
  ...component,
  initialState: () => {isBomb: false, isRevealed: false},
  reducer: (action, state) =>
    switch (action) {
    | Reveal => ReasonReact.Update({...state, isRevealed: true})
    },
  render: _self =>
    MaterialUi.(
      <Grid item=true className=cellClass>
        <Paper className=cellPaper elevation={`Int(1)} square=true>
          {
            Random.self_init();
            switch (Random.int(4)) {
            | 0 => <MaterialUIIcons.Alarm />
            | _ => "" |> ReasonReact.string
            };
          }
        </Paper>
      </Grid>
    ),
};