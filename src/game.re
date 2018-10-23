let component = ReasonReact.statelessComponent("Game");

let make = _children => {
  ...component,
  render: _self => <Board width=8 height=8 mines=10 />,
};