const fs = require('fs')

const filename = 'input.txt'
const file = fs.readFileSync(filename).toString('utf8')

// parse input
const [polymerTemplate, pairInsertionRulesStr] = file.split('\n\n')
const rulesList = pairInsertionRulesStr.split('\n')
    .map(line => line.split(' -> '))
    .map(([pattern, element]) => ({pattern, element}))

// returns an object mapping pair -> (element, 0)
const makePairsFromTemplate = (template, rules) =>
    Object.fromEntries(rules.map(({pattern, element}) => ([pattern, {element, count: 0}])))

// copy the pairs object and set all counters to zero
const copyPairsAndResetCounters = (pairs) => {
    const newPairs = { ...pairs }
    Object.keys(newPairs).map(pair => newPairs[pair] = {...pairs[pair], count: 0})
    return newPairs
}

// count the number of each pair in the template
const populatePairsObject = (pairs, template) => {
    for (let i = 1; i < template.length; i++)
        pairs[[template[i-1] + template[i]]].count++
}

// evolve the frequency of each of the pairs
// 1. if we have N pairs AB, this will result into having N pairs [AX, XB] after evolution
const evolvePairs = (pairs) => {
    const evolvedPairs = copyPairsAndResetCounters(pairs)
    for (const [pair, {element, count}] of Object.entries(pairs))
        [pair[0] + element, element + pair[1]].forEach(pair => evolvedPairs[pair].count += count)
    return evolvedPairs
}

// perform multiple evolvePairs() sequentially
const multipleEvolutions = (pairs, numTimes) => Array.from(Array(numTimes)).reduce((pairs) => evolvePairs(pairs), pairs)

const elementFrequencies = (pairs, template) => {
    const freqs = {}
    for (const [pair, {count}] of Object.entries(pairs))
        pair.split('').forEach(e => freqs[e] = count / 2 + ((e in freqs) ? freqs[e] : 0))
    // first and last element are undercounted by 1/2
    freqs[template[0]]                 += 1/2
    freqs[template[template.length-1]] += 1/2
    return freqs
}

const getGreatestElementDifference = (pairs, template) => {
    const frequencies = Object.entries(elementFrequencies(pairs, template)).map(([element, count]) => count)
    return Math.max(...frequencies) - Math.min(...frequencies)
}

const greatestElementDifferenceAfterNSteps = (polymerTemplate, rulesList, numSteps) => {
    const pairs = makePairsFromTemplate(polymerTemplate, rulesList)
    populatePairsObject(pairs, polymerTemplate)
    const finalPairs = multipleEvolutions(pairs, numSteps)
    return getGreatestElementDifference(finalPairs, polymerTemplate)
}

console.log('Part 1, What do you get if you take the quantity of the most common element and subtract the quantity of the least common element? =', greatestElementDifferenceAfterNSteps(polymerTemplate, rulesList, 10))
console.log('Part 2, What do you get if you take the quantity of the most common element and subtract the quantity of the least common element? =', greatestElementDifferenceAfterNSteps(polymerTemplate, rulesList, 40))