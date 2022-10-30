const fs = require('fs')

const filename = 'input.txt'
const file = fs.readFileSync(filename).toString('utf8')

const positions = file.split(',').map(str => parseInt(str))

// solution below only works if lowest position is 0
console.assert(Math.min(...positions) === 0, "Solution only works if min(input) == 0")

// get fuel costs based on distance (part 1 & part 2)
const constantCostOfMovement = (distance) => distance
const progressiveCostOfMovement = (distance) => (distance * (distance + 1)) / 2

const costsOfMovingToPosition = (costEstimator) => [...Array(Math.max(...positions)).keys()]
    .map(target => positions
        .map(current => costEstimator(Math.abs(current - target)))
        .reduce((a, b) => a + b, 0))

console.log('Part 1, How much fuel must they spend to align to that position? =', Math.min(...costsOfMovingToPosition(constantCostOfMovement)))
console.log('Part 2, How much fuel must they spend to align to that position? =', Math.min(...costsOfMovingToPosition(progressiveCostOfMovement)))
