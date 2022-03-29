type WindowStates = "open" | "closed" | "minimized";
type StringOrNumber = string | number

//type ObjectWithNameArray = Array<{ name: string }>;
//let objarr : ObjectWithNameArray = [
//	{name: "five", value: 5}, // does not compile bc no such key (value) allowed!
//	{name: "twentytwo"},
//	//{value: 8}
//];

// however:
//interface ObjectWithName {
//	name: string
//};

//type ObjectWithNameArray = Array<ObjectWithName>;
//let objarr : ObjectWithNameArray = [
//	{name: "five", value: 5}, // does not compile bc no such key (value) allowed!
//	{name: "twentytwo"},
//	//{value: 8}
//];


interface ObjectWithAtLeastName {
    name: string;
    // Keys can be strings, numbers, or symbols.
    // If you know it to be strings only, you can also restrict it to that.
    // For the value you can use any or unknown,
    // with unknown being the more defensive approach.
    [x: string | number | symbol]: unknown;
}

type ObjectWithAtLeastNameArray = Array<ObjectWithAtLeastName>;
const objarr2 : ObjectWithAtLeastNameArray = [
	{name: "five", value: 5},
	{name: "twentytwo"},
	//{value: 8}
];

const nextWindowState = (state: WindowStates) : WindowStates => {
	if (state == "open") {
		return "closed";
	} else if (state == "closed") {
		return "minimized"
	} else {
		return "open"
	}
}

const toStr = (input: StringOrNumber) : string => {
	return "" + input;
}

console.log('nextWindowState(open) = ', nextWindowState("open"));

console.log(objarr2);

console.log('5 and something to string: ', toStr(5), toStr("something"));

