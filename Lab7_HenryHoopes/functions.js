function validation() {
    var p1 = document.getElementById("p1").value;
    var p2 = document.getElementById("p2").value;


    if (p1.length < 8) {
        alert("Your first password is less than 8 letters!")
    } else if (p2.length < 8) {
        alert("Your second password is less than 8 letters!")
    } else if (p1 != p2) {
        alert("Your passwords do not match!")
    } else {
        alert("Your passwords match!")
    }
}

function change_color() {
    var bdrR = document.getElementById("bdrR").value;
    var bdrG = document.getElementById("bdrG").value;
    var bdrB = document.getElementById("bdrB").value;
    var bdrWidth = document.getElementById("bdrWidth").value;
    var bgR = document.getElementById("bgR").value;
    var bgG = document.getElementById("bgG").value;
    var bgB = document.getElementById("bgB").value;

    var tag = document.getElementById("paragraph");
    tag.style.borderColor = `rgb(${bdrR},${bdrG},${bdrB})`;
    tag.style.borderWidth = bdrWidth;
    tag.style.backgroundColor = `rgb(${bgR},${bgG},${bgB})`;
}
