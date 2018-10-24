// Generated by BUCKLESCRIPT VERSION 4.0.6, PLEASE EDIT WITH CARE
'use strict';

var Css = require("bs-css/src/Css.js");
var Block = require("bs-platform/lib/js/block.js");
var Random = require("bs-platform/lib/js/random.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var MaterialUIIcons = require("bs-material-ui-icons/src/MaterialUIIcons.js");
var MaterialUi_Grid = require("@jsiebern/bs-material-ui/src/MaterialUi_Grid.bs.js");
var MaterialUi_Paper = require("@jsiebern/bs-material-ui/src/MaterialUi_Paper.bs.js");

var cellClass = Css.style(/* :: */[
      Css.width(Css.px(50)),
      /* :: */[
        Css.height(Css.px(50)),
        /* :: */[
          Css.important(Css.margin(Css.px(3))),
          /* [] */0
        ]
      ]
    ]);

var cellPaper = Css.style(/* :: */[
      Css.height(Css.pct(100.0)),
      /* :: */[
        Css.width(Css.pct(100.0)),
        /* :: */[
          Css.justifyContent(/* center */98248149),
          /* :: */[
            Css.alignItems(/* center */98248149),
            /* :: */[
              Css.display(Css.flexBox),
              /* :: */[
                Css.important(Css.backgroundColor(Css.hex("fcfcfc"))),
                /* [] */0
              ]
            ]
          ]
        ]
      ]
    ]);

var component = ReasonReact.reducerComponent("Cell");

function make() {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */component[/* didMount */4],
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function () {
              var match = Random.$$int(2);
              return ReasonReact.element(undefined, undefined, MaterialUi_Grid.make(undefined, undefined, cellClass, undefined, undefined, undefined, true, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, /* array */[ReasonReact.element(undefined, undefined, MaterialUi_Paper.make(cellPaper, undefined, /* `Int */[
                                        3654863,
                                        1
                                      ], true, undefined, undefined, /* array */[match !== 0 ? (
                                            match !== 1 ? null : ReasonReact.element(undefined, undefined, MaterialUIIcons.Alarm[/* make */0](/* array */[]))
                                          ) : ""]))]));
            }),
          /* initialState */(function () {
              return /* record */[
                      /* isBomb */false,
                      /* isRevealed */false
                    ];
            }),
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */(function (_, state) {
              return /* Update */Block.__(0, [/* record */[
                          /* isBomb */state[/* isBomb */0],
                          /* isRevealed */true
                        ]]);
            }),
          /* jsElementWrapped */component[/* jsElementWrapped */13]
        ];
}

exports.cellClass = cellClass;
exports.cellPaper = cellPaper;
exports.component = component;
exports.make = make;
/* cellClass Not a pure module */
