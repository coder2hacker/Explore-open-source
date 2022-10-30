const fs = require('fs');
const { performance } = require("perf_hooks");

const filename = 'input.txt'
const file = fs.readFileSync(filename).toString('utf8')

// parse input
const grid = file.split('\n').map(line => line.split('').map(n => parseInt(n)))

/**
 * WARNING: SADNESS
 * This implementation is quite slow due to not using priority queues.
 * Finding the minimum in an array is O(n), and I'm doing it O(n) times.
 * Replacing Q's implementation with a priority queue (e.g. binary min-heap) should improve it dramatically
 *   - extracting the minimum becomes O(log n) in the worst case, and probably better on the average case.
 */

function dijkstra(lengths) {
    // some auxiliary functions
    const [numRows, numCols] = [lengths.length, lengths[0].length]
    const destination = {row: numRows - 1, col: numCols - 1}
    const vertexNeighborsOf = ({row, col}) => [
        {row: row + 1, col}, {row: row - 1, col}, {row, col: col - 1}, {row, col: col + 1}
    ].filter(({row, col}) => row >= 0 && row < numRows && col >= 0 && col < numCols)
    const cost = v => dist[v.row][v.col] + numRows - v.row + numCols - v.col

    // create vertex set Q
    let Q = []
    // for each vertex v in Graph: dist[v] <- INFINITY
    const dist = lengths.map((row, rowIndex) => row.map((_, colIndex) => Infinity))
    // for each vertex v in Graph: add v to Q
    lengths.forEach((r, row) => r.map((_, col) => Q.push({row, col})))
    // index for efficient lookup if vertex is in Q
    const isInQ = lengths.map((row, rowIndex) => row.map((_, colIndex) => true))
    // dist[source] <- 0
    dist[0][0] = 0

    let timeFindMin = 0
    const start = performance.now()

    while (Q.length > 0) { // while Q is not empty:
        // get vertex in Q with min dist[u] and remove u from Q
        const start = performance.now()
        let minIndex = 0
        for (let i = 1; i < Q.length; i++) {
            // Dijkstra:
            if (dist[Q[i].row][Q[i].col] < dist[Q[minIndex].row][Q[minIndex].col])
                    minIndex = i
        }
        timeFindMin += performance.now() - start
        const u = Q[minIndex]
        // remove u from Q
        Q[minIndex] = Q[Q.length - 1]
        Q.pop()
        isInQ[u.row][u.col] = false

        // optimization: if u = destination, we can terminate search
        if (u.row == destination.row && u.col == destination.col) break

        // for each neighbor v of u still in Q:
        vertexNeighborsOf(u).filter(v => isInQ[v.row][v.col]).forEach(v => {
            const alt = dist[u.row][u.col] + lengths[v.row][v.col] // alt <- dist[u] + length(u, v)
            if (alt < dist[v.row][v.col]) dist[v.row][v.col] = alt // if alt < dist[v] then dist[v] <- alt
        })
    }
    const timeTotal = performance.now() - start
    console.log('Time taken just to find minimums:', timeFindMin, 'milliseconds')
    console.log('Total time to compute shortest path:', timeTotal, 'milliseconds')

    // return only the distance to the destination
    return dist[destination.row][destination.col]
}

const expandPosition = (grid, {row, col}) =>
    [0, 1, 2, 3, 4].map(subRow => [0, 1, 2, 3, 4].map(subCol => ({
        row: row + grid.length * subRow,
        col: col + grid[0].length * subCol,
        risk: ((grid[row][col] + subRow + subCol - 1) % 9 + 1)
    }))).flat()

const expandGrid = (grid) => {
    const expandedGrid = Array.from(Array(grid.length*5)).map(_ => Array.from(Array(grid[0].length*5)))
    for (let row = 0; row < grid.length; row++)
        for (let col = 0; col < grid.length; col++)
            expandPosition(grid, {row, col}).forEach(({row, col, risk}) => expandedGrid[row][col] = risk)
    return expandedGrid
}

//console.log('Part 1, What is the lowest total risk of any path from the top left to the bottom right? =', dijkstra(grid))
console.log('Part 2 =', dijkstra(expandGrid(grid)))