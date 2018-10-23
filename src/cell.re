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
    Css.width(Css.px(30)),
    Css.height(Css.px(30)),
    Css.display(`inlineBlock),
    Css.border(Css.px(1), `solid, Css.black),
    Css.borderCollapse(`collapse),
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
    <div className=cellClass> {"Cell" |> ReasonReact.string} </div>,
};