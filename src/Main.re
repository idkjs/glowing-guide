/* State declaration */
type state = {
  file: string
};

/* Action declaration */
type action =
  | Upload(string) 

module M = {
  [@bs.val] [@bs.scope "URL"]
  external createObjectURL: Webapi.File.t => string = "";
};

module Styles = {
  open Css;

  global("body", [margin(px(0))])
  let main = style([
    display(flexBox),
    background(rgba(60,60,60, 0.1))
  ]);
};

/* <div className=Styles.card>
  <h1 className=Styles.title> (ReasonReact.stringToElement("Hello")) </h1>
  <button className=Styles.actionButton(false)>
</div> */

[@react.component]
let make = () => {
  let (state, dispatch) =
    React.useReducer(
      (_state, action) =>
        switch (action) {
        | Upload(url) => {file: url}
        },
      {file: ""},
    );
  <div className=Styles.main>
    <div>
      <Button text={"foo"} cb={(_) => dispatch(Upload("bar"))}/>
      <input
        type_="file"
        onChange={event => {
          let f = ReactEvent.Form.target(event)##files;
          dispatch(Upload(M.createObjectURL(f[0])));

        }}
      />
    </div>
    <img src={state.file}/>
  </div>;
};
