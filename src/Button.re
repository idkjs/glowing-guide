[@react.component]
let make = (~text, ~cb) => {
  <button onClick={e => cb(e)}> {React.string(text)} </button>;
};
