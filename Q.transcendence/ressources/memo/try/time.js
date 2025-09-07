
// function wait(duration) {
//     return new Promise((resolve) => {
//         setTimeout(() => {
//             resolve(duration);
//         }, duration);
//     });
// }

// // setTimeout(function, delay)
// // function to execute after delay as waitlist
// // condition non blocking function ex prompt
// // return timout ID
// const timeoutId = setTimeout(() => {
// 	console.log("Hello after 2 seconds");
// }, 2000);

// // clearTimeout to stop the timeout
// const clearTimeout = () => {
// 	clearTimeout(timeoutId);
// }

// // setInterval(function, delay)
// // function to execute every delay milliseconds
// // condition non blocking function ex prompt
// // return interval ID
// const intervalId = setInterval(() => {
// 	console.log("Hello every 2 seconds");
// }, 2000);

// // clearInterval to stop the interval
// const clearInterval = () => {
// 	clearInterval(intervalId);
// }

// // BUT avoid callback hell
// setTimeout(() => {
// 	console.log("Hello after 2 seconds");
// 	setTimeout(() => {
// 		console.log("Hello after 4 seconds");
// 		setTimeout(() => {
// 			console.log("Hello after 6 seconds");
// 			// continue the chain
// 		}, 2000);
// 	}, 2000);
// }, 2000);


// // Promises

// const p = new Promise((resolve, reject) => {
// 	resolve(4)
// 	// reject(5)
// });

// p.then((n) => {
// 	console.log(n); // 4
// });

// p.catch((n) => {
// 	console.log(n); // 5
// });

// // or <=>
// p.then((n) => {
// 	console.log(n); // 4
// }).catch((n) => {
// 	console.log(n); // 5
// });

// // chaining
// p.then((n) => {
// 	console.log(n); // 4
// 	return 3;
// }).then((n) => {
// 	console.log(n); // 3
// }).catch((n) => {
// 	console.log(n); // 5
// });


// p.then((n) => {
// 	console.log(n); // 4
// }).catch((n) => {
// 	console.log(n); // 5
// }).finally(() => {
// 	console.log("printed anyway");
// });


// // example with wait

// function waitAndFail(duration) {
// 	return  new Promise((resolve, reject) => {
// 		setTimeout(() => {
// 			reject(duration);
// 		}, duration);
// 	})
// }

// // 2 lvl callback
// wait(2000)
// 	.then(() => {
// 		console.log("Waited 2 seconds");
// 		return wait(1000);
// 	}).then(() => {
// 		console.log("Waited 1 second");
// 		return waitAndFail(1000);
// 	}).catch((duration) => {
// 		console.log(`Failed after ${duration} milliseconds`);
// 	});

// // await reserved for async functions
// // async function main () {
// // 	try {
// // 		await wait(2000);
// // 		console.log("Waited 2 seconds");
// // 		await wait(1000);
// // 		console.log("Waited 1 second");
// // 		await waitAndFail(1000);
// // 	} catch (duration) {
// // 		console.log(`Failed after ${duration} milliseconds`);
// // 	}
// // }

// async function main () {
// 	const duration = await wait(2000);
// 	console.log(`Waited ${duration} milliseconds`);
// 	return 5;
// }

// main()
// 	.then((n) => console.log(n)) // 5 printed after 2 seconds
// 	.catch((duration) => console.log(`Failed after ${duration} milliseconds`))
// 	.finally(() => {
// 		console.log("Finished");
// 	});

// // Promise.all() method takes an array of promises and resolves when all of them have resolved
// // returns a single promise that resolves to an array of the results
// // rejects automatically if any of the promises reject
// Promise.all([wait(2000), wait(1000), wait(3000)])
// 	.then((durations) => {
// 		console.log(`All promises resolved after ${Math.max(...durations)} milliseconds`);
// 	})
// 	.catch((duration) => {
// 		console.log(`Failed after ${duration} milliseconds`);
// 	});

// // Promise.allSettled() method takes an array of promises and resolves when all of them have settled
// // returns a single promise that resolves to an array of the results and their statuses
// // does not reject if any of the promises reject
// Promise.allSettled([wait(2000), waitAndFail(1000), wait(3000)])
// 	.then(console.log)
// 	.catch(console.log)

// // Promise.any() method takes an array of promises and resolves when any of them have resolved
// // returns a single promise that resolves to the value of the first resolved promise
// // rejects if all of the promises reject
// Promise.any([waitAndFail(2000), waitAndFail(1000), wait(3000)])
// 	.then((duration) => {
// 		console.log(`First promise resolved after ${duration} milliseconds`);
// 	})
// 	.catch((duration) => {
// 		console.log(`All promises rejected after ${duration} milliseconds`);
// 	});
// // returns only the value of the first resolved promise which is the wait(3000) promise


// // Promise.race() method takes an array of promises and resolves when the first promise resolves or rejects
// // returns a single promise that resolves or rejects with the value or reason of the first settled promise
// Promise.race([waitAndFail(2000), waitAndFail(1000), wait(3000)])
// 	.then((duration) => {
// 		console.log(`First promise settled after ${duration} milliseconds`);
// 	})
// 	.catch((duration) => {
// 		console.log(`All promises rejected after ${duration} milliseconds`);
// 	});
// // 

function waitSync(duration) {
	const start = Date.now();
	while (Date.now() - start < duration) {
		// busy-wait
	}
}

const p_sync = new Promise((r) => {
	console.log('Hello')
	r(5)
})

// is asynchronous
p_sync.then(() => {
	console.log('then');
});

waitSync(2000);

console.log('World')


// bad practice because it uses await unnecessarily and create extra promise lvl
// loose of performance
// async function waitAndLog_0(duration, msg) {
// 	return await wait(duration).then(() => {
// 		console.log(msg);
// 	});
// }

// good practice
function waitAndLog(duration, msg) {
	return wait(duration).then(() => {
		console.log(msg);
	});
}