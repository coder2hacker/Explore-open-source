const mongoose = require('mongoose')
const shortId = require('shortid')
const shortUrlSchema = new mongoose.Schema({
    full: {
        type: String,
        required: true
    },
    short: {
        type: String,
        required: true,
        unique: true,
        default: shortId.generate
    },
    createdAt: {
        type: Date,
        required: true,
        default: new Date(),
        unmodifiable: true

    },
    lastVisitedAt: {
        type: Date,
        required: true,
        default: new Date()
    },
    clicks: {
        type: Number,
        required: true,
        default: 0
    }
})
module.exports = mongoose.model('ShortUrl', shortUrlSchema);