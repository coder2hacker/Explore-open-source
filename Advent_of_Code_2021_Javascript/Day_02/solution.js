const fs = require('fs')

const filename = 'input.txt'
const file = fs.readFileSync(filename).toString('utf8')

const commands = file
    .split('\n')
    .map(line => line.split(' '))
    .map(([direction, unitsStr]) => ({
        direction,
        units: parseInt(unitsStr)
    }))

function computePositionPartOne(commands) {
    var horizontalPosition = 0
    var depth = 0
    for (const command of commands) {
        switch (command.direction) {
            case 'forward':
                horizontalPosition += command.units;
                break;
            case 'down':
                depth += command.units;
                break;
            case 'up':
                depth -= command.units;
                break;
        }
    }
    return horizontalPosition * depth;
}

function computePositionPartTwo(commands) {
    var horizontalPosition = 0
    var depth = 0
    var aim = 0
    for (const command of commands) {
        switch (command.direction) {
            case 'forward':
                horizontalPosition += command.units;
                depth += aim * command.units;
                break;
            case 'down':
                aim += command.units;
                break;
            case 'up':
                aim -= command.units;
                break;
        }
    }
    return horizontalPosition * depth;
}

console.log('Part 1, What do you get if you multiply your final horizontal position by your final depth? =', computePositionPartOne(commands));
console.log('Part 2, What do you get if you multiply your final horizontal position by your final depth? =', computePositionPartTwo(commands));