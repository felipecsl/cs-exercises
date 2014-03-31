var FourWayFloodFill = function() {
  this.run = function(matrix, x, y, newValue) {
    this.matrix = matrix;
    this.oldValue = matrix[x][y];
    this.newValue = newValue;

    return this.fill(x, y);
  };

  this.fill = function(x, y) {
    var item = this.matrix[x][y];

    if(item != this.oldValue) {
      return;
    }

    this.matrix[x][y] = this.newValue;

    if(x > 0) {
      this.fill(x - 1, y);
    }
    if(y < this.matrix[0].length - 1) {
      this.fill(x, y + 1);
    }
    if(y > 0) {
      this.fill(x, y - 1);
    }
    if(x < this.matrix.length - 1) {
      this.fill(x + 1, y);
    }
  }
};