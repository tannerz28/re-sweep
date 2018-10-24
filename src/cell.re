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
  Css.style([Css.width(Css.px(50)), Css.height(Css.px(50))]);

let component = ReasonReact.reducerComponent("Cell");

let make = _children => {
  ...component,
  initialState: () => {isBomb: false, isRevealed: false},
  reducer: (action, state) =>
    switch (action) {
    | Reveal => ReasonReact.Update({...state, isRevealed: true})
    },
  render: _self =>
    <MaterialUi.Grid item=true className=cellClass>
      <div> {"Cell" |> ReasonReact.string} </div>
    </MaterialUi.Grid>,
};