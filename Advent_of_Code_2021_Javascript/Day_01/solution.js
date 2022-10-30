const fs = require('fs')

const filename = 'input.txt'
const file = fs.readFileSync(filename).toString('utf8')

const depthReadings = file.split('\n').map(x => parseInt(x, 10))

function computeNumDepthIncreasesOfWindow(depthReadings, windowSize) {
    var numDepthIncreases = 0;
    for (var i = windowSize; i < depthReadings.length; i++)
        if (depthReadings[i] > depthReadings[i-windowSize])
            numDepthIncreases++;
    return numDepthIncreases;
}

console.log('Part 1, How many measurements are larger than the previous measurement? =', computeNumDepthIncreasesOfWindow(depthReadings, 1));
console.log('Part 2, How many sums are larger than the previous sum? =', computeNumDepthIncreasesOfWindow(depthReadings, 3));