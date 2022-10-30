const fs = require('fs')

const filename = 'input.txt'
const file = fs.readFileSync(filename).toString('utf8')

const lines = file.split('\n')
    .map(line => line.split(' -> ')
        .map(pos => pos.split(',').map(n => parseInt(n)))
        .map(([x, y]) => ({x, y}))
        .sort((a, b) => a.x != b.x ? a.x - b.x : a.y - b.y)
    )
    .map(([from, to]) => ({from, to}))

const isHorizontalLine       = (line) => line.from.x !== line.to.x && line.from.y === line.to.y
const isVerticalLine         = (line) => line.from.x === line.to.x && line.from.y !== line.to.y
const isNegativeDiagonalLine = (line) => line.from.x  <  line.to.x && line.from.y  >  line.to.y
const isPositiveDiagonalLine = (line) => line.from.x  <  line.to.x && line.from.y  <  line.to.y
const isHorizontalOrVerticalLine = (line) => isHorizontalLine(line) || isVerticalLine(line)

const lineLength = (line) => 1 + Math.max(
    Math.abs(line.from.x - line.to.x),
    Math.abs(line.from.y - line.to.y)
)

const lineDirection = (line) => {
    if (isHorizontalLine(line))       return {x: 1, y: 0}
    if (isVerticalLine(line))         return {x: 0, y: 1}
    if (isPositiveDiagonalLine(line)) return {x: 1, y: 1}
    if (isNegativeDiagonalLine(line)) return {x: 1, y: -1}
    throw Error("Unknown line direction")
}

const lineSegmentCoordinates = (line) => {
    const direction = lineDirection(line)
    return Array.from(Array(lineLength(line)).keys())
        .map(i => ({
            x: line.from.x + i * direction.x,
            y: line.from.y + i * direction.y
        }))
}

const diagramDimensions = (lines) => ({
    x: Math.max(...lines.map(line => [line.from.x, line.to.x]).flat()) + 1,
    y: Math.max(...lines.map(line => [line.from.y, line.to.y]).flat()) + 1
})

const createDiagram = ({x, y}) => Array.from(Array(y), () => new Array(x).fill(0))

const printDiagram = (diagram) => diagram.forEach(line => console.log(line.join(' ')))

const markLinesOnDiagram = (lines, diagram) =>
    lines.forEach(line => lineSegmentCoordinates(line)
        .forEach(({x, y}) => diagram[y][x]++))

const countIntersections = (diagram) => diagram.flat().filter(n => n > 1).length

const diagramPart1 = createDiagram(diagramDimensions(lines))
markLinesOnDiagram(lines.filter(isHorizontalOrVerticalLine), diagramPart1)
//printDiagram(diagramPart1)
console.log('Part 1, At how many points do at least two lines overlap? = ', countIntersections(diagramPart1))

const diagramPart2 = createDiagram(diagramDimensions(lines))
markLinesOnDiagram(lines, diagramPart2)
//printDiagram(diagramPart2)
console.log('Part 2, At how many points do at least two lines overlap? =', countIntersections(diagramPart2))