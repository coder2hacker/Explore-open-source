const fs = require('fs')

const filename = 'input.txt'
const file = fs.readFileSync(filename).toString('utf8')

const [drawnNumbersString, ...boardStrings] = file.split('\n\n')
const drawnNumbers = drawnNumbersString.split(',').map(n => parseInt(n))
const boards = boardStrings
    .map(boardString => boardString.split('\n')
        .map(rowString => rowString.trim().split(/\s+/).map(n => parseInt(n))))

const MARKED = 'X'

function markNumberOnBoard(board, number) {
    for (let i = 0; i < board.length; i++)
        for (let j = 0; j < board[i].length; j++)
            if (board[i][j] === number)
                board[i][j] = MARKED
}

function boardIsWinner(board) {
    for (let i = 0; i < board.length; i++) {
        // check if row is complete
        if (board[i].every(x => x === MARKED)) return true
        // check if column is complete
        if (board.map(row => row[i]).every(x => x === MARKED)) return true
    }
    return false
}

function getBoardScore(board, lastDrawnNumber) {
    let sumUnmarkedNumbers = 0
    for (let i = 0; i < board.length; i++)
        for (let j = 0; j < board[i].length; j++)
            if (board[i][j] !== MARKED)
                sumUnmarkedNumbers += board[i][j]
    return sumUnmarkedNumbers * lastDrawnNumber
}

function checkWinners(boards) {
    let stillPlaying = []
    let winners = []
    for (const board of boards) {
        if (boardIsWinner(board))
            winners.push(board)
        else
            stillPlaying.push(board)
    }
    return { winners, stillPlaying }
}

function playBingo(remainingBoards, drawnNumbers) {
    let scores = []
    while (remainingBoards.length > 0) {
        const number = drawnNumbers.shift()
        remainingBoards.forEach(board => markNumberOnBoard(board, number))
        const { winners, stillPlaying } = checkWinners(remainingBoards)
        winners.forEach(winner => scores.push(getBoardScore(winner, number)))
        remainingBoards = stillPlaying
    }
    return scores
}

const scores = playBingo(boards, drawnNumbers)
console.log('SCORES:', scores)
console.log('Part 1, What will your final score be if you choose that board? =', scores[0])
console.log('Part 2, what would its final score be?=', scores[scores.length - 1])