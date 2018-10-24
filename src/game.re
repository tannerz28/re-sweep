let component = ReasonReact.statelessComponent("Game");

let mainClass =
  Css.style([Css.display(Css.flexBox), Css.justifyContent(`center)]);

let make = _children => {
  ...component,
  render: _self =>
    <main className=mainClass>
      MaterialUi.(
        <Grid xs=V4 justify=`Center>
          <Paper> <Grid> <Board width=8 height=8 mines=10 /> </Grid> </Paper>
        </Grid>
      )
    </main>,
};