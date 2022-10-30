const fs = require('fs')

const filename = 'input.txt'
const file = fs.readFileSync(filename).toString('utf8')

const bits = file.split('\n')

// compute array describing how many 1's are in each position/column
function getBitSums(bits) {
    return bits.reduce((sum, value) => {
        const valueBits = value.split('').map(x => parseInt(x))
        return sum.map((n, i) => n + valueBits[i])
    }, new Array(bits[0].length).fill(0))
}

// get array of most common bits
function getMostCommonBits(bits) {
    return getBitSums(bits).map(mostCommonBitsFilter(bits))
}

function getLeastCommonBits(bits) {
    return getMostCommonBits(bits).map(x => x ? 0 : 1)
}

function filterValues(bits, filter) {
    for (let i = 0; i < bits[0].length && bits.length > 1; i++) {
        const bitFilter = getBitSums(bits).map(filter(bits))[i]
        bits = bits.filter(x => x[i] === '' + bitFilter)
    }
    console.assert(bits.length === 1)
    return bits
}

const mostCommonBitsFilter  = (bits) => (e) => e >= bits.length / 2 ? 1 : 0
const leastCommonBitsFilter = (bits) => (e) => e < bits.length / 2 ? 1 : 0

const gammaRate = parseInt(getMostCommonBits(bits).join(''), 2)
const epsilonRate = parseInt(getLeastCommonBits(bits).join(''), 2)
const oxygenGeneratorRating = parseInt(filterValues(bits, mostCommonBitsFilter).join(''), 2)
const co2ScrubberRating = parseInt(filterValues(bits, leastCommonBitsFilter).join(''), 2)

console.log('Part 1, What is the power consumption of the submarine?  =', (gammaRate * epsilonRate))
console.log('Part 2, What is the life support rating of the submarine? =', (oxygenGeneratorRating * co2ScrubberRating))