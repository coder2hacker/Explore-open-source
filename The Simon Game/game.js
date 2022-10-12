let buttonColors = ['red', 'blue', 'green', 'yellow'];
var gamePattern = [];
var userClickedPattern = [];
var level = 0;
var hasGameStarted = false;

function nextSequence() {

    let randomChosenColour = buttonColors[Math.floor(Math.random() * 4)];

    gamePattern.push(randomChosenColour);


    let i = 0;

    function myLoop() {
        setTimeout(function () {
            $('#' + gamePattern[i]).fadeOut(200).fadeIn(200);

            playSound(gamePattern[i]);
            i++;
            if (i < gamePattern.length) {
                myLoop();
            }
        }, 500)
    }

    myLoop();

    $('h1').text('LEVEL ' + level);

    level++;
}

$('.btn').click(
    function (event) {
        var userChosenColour = event.target.id;
        userClickedPattern.push(userChosenColour);
        playSound(userChosenColour);
        animatePress(userChosenColour)
        checkAnswer();
    }
);

function playSound(name) {
    new Audio('sounds/' + name + '.mp3').play();
}

function animatePress(currentColor) {
    $('#' + currentColor).addClass('pressed');
    setTimeout(function () {
        $('#' + currentColor).removeClass('pressed');
    }, 100);
}

$(document).on('keypress', function () {
    if (!hasGameStarted) {

        $('body').removeClass('game-over');

        hasGameStarted = !hasGameStarted;
        nextSequence();
    }
});

function checkAnswer() {
    if (userClickedPattern.every((value, index) => value === gamePattern[index])) {
        if (userClickedPattern.length == gamePattern.length) {
            setTimeout(function () {
                userClickedPattern = [];
                nextSequence();
            }, 1000);
        }
    } else {
        playSound('wrong');
        $('body').addClass('game-over');
        $('h1').text('Game Over, Press Any Key to Restart');
        startOver();
    }
}

function startOver() {
    level = 0;
    gamePattern = [];
    userClickedPattern = [];
    hasGameStarted = false;
}