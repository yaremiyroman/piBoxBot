const canvas = document.querySelector('#paintField');
const clearBtn = document.querySelector('#clear');
const sadBtn = document.querySelector('#sad');
const happyBtn = document.querySelector('#happy');
const trainBtn = document.querySelector('#train');
const predictBtn = document.querySelector('#predict');
const ctx = canvas.getContext('2d');
const paintField = new Array(100);
const trainData = [];
const NN = new Network(100, 2);
let mouseDown = false;
let happyCount = 0;
let sadCount = 0;

NN.learningRate = 0.8;

document.addEventListener('mousedown', (e) => {
    mouseDown = true;
});

document.addEventListener('mouseup', (e) => {
    mouseDown = false;
});

canvas.addEventListener('mousemove', (e) => {
    if (!mouseDown) {
        return;
    }
    draw(e);
});

clearBtn.addEventListener('click', () => {
    clearField();
});

happyBtn.addEventListener('click', () => {
    happyCount += 1;
    storeResult([1, 0]);
    clearField();
});

sadBtn.addEventListener('click', () => {
    sadCount += 1;
    storeResult([0, 1]);
    clearField();
});

predictBtn.addEventListener('click', () => {
    NN.input = [...paintField];
    const [happiness, sadness] = NN.prediction;
    alert(`I think it's a ${happiness > sadness ? 'happy' : 'sad'} face!\n
     Happiness: ${Math.round(happiness * 100)}% Sadness: ${Math.round(sadness * 100)}%`);
});

trainBtn.addEventListener('click', () => {
    NN.train(trainData, 1000).then(() => {
        predictBtn.disabled = false;
        alert('Trained!');
    })
});

clearField();
updateInterface();