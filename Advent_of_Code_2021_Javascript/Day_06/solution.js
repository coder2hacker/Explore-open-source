const fs = require('fs')

const filename = 'input.txt'
const file = fs.readFileSync(filename).toString('utf8')

const initialTimers = file.split(',').map(str => parseInt(str))

const PERIOD = 7
const BIRTH_TIMER = PERIOD + 2

// Cache values for family sizes
let familySize = {}

// Given a fish with timer zero and a given period of time,
// how big will its family size be at the end of the period?
const familySizeAtEndOfPeriod = (daysLeft) => {
    if (daysLeft <= 0) return 1
    // if never computed before, compute now!
    if (!familySize[daysLeft]) {
        familySize[daysLeft] =
            familySizeAtEndOfPeriod(daysLeft - PERIOD) +
            familySizeAtEndOfPeriod(daysLeft - BIRTH_TIMER)
    }
    // return cached (or recently-computed) value
    return familySize[daysLeft]
}

// compute the sum of family sizes of fishes with set of initial timers
const numLanternfishAtEndOfPeriod = (initialTimers, period) => initialTimers
    .map(timer => familySizeAtEndOfPeriod(period - timer))
    .reduce((a, b) => a + b, 0)

console.log('Part 1, How many lanternfish would there be after 80 days? =', numLanternfishAtEndOfPeriod(initialTimers, 80))
console.log('Part 2, How many lanternfish would there be after 256 days? =', numLanternfishAtEndOfPeriod(initialTimers, 256))