export {default as greetings} from "./hello.js";

export const sum = (items) => items.reduce((acc, item) => acc + item, 0);

export default function bye() {
	console.log("Goodbye, World!");
}
