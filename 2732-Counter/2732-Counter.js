// Last updated: 1/16/2026, 8:20:16 PM
/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {
    let counter = n

    return function() {
       return counter++;
    };
};

/**  = 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */