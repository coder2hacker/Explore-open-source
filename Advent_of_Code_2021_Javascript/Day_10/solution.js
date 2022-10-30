const fs = require('fs')

const filename = 'input.txt'
const file = fs.readFileSync(filename).toString('utf8')

const lines = file.split('\n')

const partitionArray = (array, isValid) =>
    array.reduce(([pass, fail], elem) => isValid(elem) ? [[...pass, elem], fail] : [pass, [...fail, elem]], [[], []])

const openingCharacters  = ['(', '[', '{', '<']
const closingCharacters  = [')', ']', '}', '>']
const errorScores        = [3, 57, 1197, 25137]
const autocompleteScores = [ 1,   2,   3,   4 ]

const isOpeningCharacter = (char) => openingCharacters.includes(char)
const isClosingCharacter = (char) => closingCharacters.includes(char)

const matchingCharacter     = (openingChar) => closingCharacters[openingCharacters.indexOf(openingChar)]
const areMatchingCharacters = (opening, closing) => closing === matchingCharacter(opening)

const characterErrorScore        = (char) => errorScores[closingCharacters.indexOf(char)]
const characterAutocompleteScore = (char) => autocompleteScores[openingCharacters.indexOf(char)]

const autocompleteScore = (stack) =>
    (stack.length == 0) ? 0 : characterAutocompleteScore(stack[0]) + 5 * autocompleteScore(stack.slice(1))

const lineScore = (line) => {
    let stack = []
    for (let i = 0; i < line.length; i++) {
        if (isClosingCharacter(line[i]) && !areMatchingCharacters(stack[stack.length-1], line[i])) {
            return {
                score: characterErrorScore(line[i]),
                isIllegal: true
            }
        }
        if (isOpeningCharacter(line[i])) stack.push(line[i])
        if (isClosingCharacter(line[i])) stack.pop()
    }
    return {
        score: autocompleteScore(stack),
        isIllegal: false
    }
}

const [illegal, incomplete] = partitionArray(lines.map(line => lineScore(line)), (lineScore => lineScore.isIllegal))
    .map(lines => lines.map(line => line.score))

console.log('Part 1, What is the total syntax error score for those errors? =', illegal.reduce((a, b) => a + b, 0))
console.log('Part 2, What is the middle score? =', incomplete.sort((a, b) => b - a)[Math.floor(incomplete.length/2)])
