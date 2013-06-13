var FourWayEdgeFill = function() {
  this.run = function(matrix, x, y, newValue) {
    this.matrix = matrix;
    this.oldValue = matrix[x][y];
    this.newValue = newValue;
    this.mark = [];

    for(var i = 0; i < matrix.length; i++) {
      this.mark.push([]);

      for(var j = 0; j < matrix[0].length; j++) {
        this.mark[i].push(false);
      }
    }

    return this.fill(x, y);
  };

  this.fill = function(x, y) {
    this.mark[x][y] = true;

    var item = this.matrix[x][y];

    if(item != this.oldValue) {
      this.matrix[x][y] = this.newValue;
      return;
    }

    if(x > 0 && !this.mark[x - 1][y]) {
      this.fill(x - 1, y);
    }
    if(y > 0 && !this.mark[x][y - 1]) {
      this.fill(x, y - 1);
    }
    if(x < this.matrix.length - 1 && !this.mark[x + 1][y]) {
      this.fill(x + 1, y);
    }
    if(y < this.matrix[0].length - 1 && !this.mark[x][y + 1]) {
      this.fill(x, y + 1);
    }
  }
};