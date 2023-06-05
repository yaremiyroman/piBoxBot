function drawGrid() {
    ctx.strokeStyle = '#CCC'

    for (let i = 1; i < 10; i++) {
        ctx.moveTo(0, i * 40);
        ctx.lineTo(400, i * 40);
        ctx.moveTo(i * 40, 0);
        ctx.lineTo(i * 40, 400);
    }

    ctx.stroke();
}

function clearCanvas() {
    ctx.fillStyle = '#FFF';
    ctx.fillRect(0, 0, 400, 400);
    drawGrid();
}

function drawSquare(row, column, color) {
    ctx.fillStyle = color;
    ctx.fillRect(column * 40 + 1, row * 40 + 1, 38, 38);
}

function draw(event) {
    const rowIndex = Math.floor(event.offsetY / 40);
    const columnIndex = Math.floor(event.offsetX / 40);
    const arrayIndex = rowIndex * 10 + columnIndex;
    paintField[arrayIndex] = 1;
    const color = paintField[arrayIndex] ? 'green' : 'white';
    drawSquare(rowIndex, columnIndex, color);
}

function clearField() {
    paintField.fill(false);
    clearCanvas(ctx)
}

function updateInterface() {
    happyBtn.innerText = `🤗 ${happyCount}`;
    sadBtn.innerText = `🤬 ${sadCount}`;
}

function storeResult(value) {
    trainData.push([[...paintField], value]);
    updateInterface()
}
