describe("FourWayFloodFill", function() {
  var floodFill;

  beforeEach(function() {
    floodFill = new FourWayFloodFill();
  });

  it("should flood fill a matrix", function() {
    var printMatrix = function(matrixToPrint) {
      for(var i = 0; i < matrixToPrint.length; i++) {
        for(var j = 0; j < matrixToPrint[i].length; j++) {
          jasmine.log(matrixToPrint[i][j] + " ");
        }
        jasmine.log("<br>");
      }
    };

    var matrix = [
      [1, 1, 1, 1, 1, 1, 1, 1, 1],
      [1, 1, 1, 1, 1, 1, 1, 1, 1],
      [1, 1, 0, 0, 0, 0, 0, 1, 1],
      [1, 1, 0, 0, 0, 0, 0, 1, 1],
      [1, 1, 0, 0, 0, 0, 0, 1, 1],
      [1, 1, 0, 0, 0, 0, 0, 1, 1],
      [1, 1, 0, 0, 0, 0, 0, 1, 1],
      [1, 1, 1, 1, 1, 1, 1, 1, 1],
      [1, 1, 1, 1, 1, 1, 1, 1, 1]
    ];

    var expectedMatrix = [
      [1, 1, 1, 1, 1, 1, 1, 1, 1],
      [1, 1, 1, 1, 1, 1, 1, 1, 1],
      [1, 1, 2, 2, 2, 2, 2, 1, 1],
      [1, 1, 2, 2, 2, 2, 2, 1, 1],
      [1, 1, 2, 2, 2, 2, 2, 1, 1],
      [1, 1, 2, 2, 2, 2, 2, 1, 1],
      [1, 1, 2, 2, 2, 2, 2, 1, 1],
      [1, 1, 1, 1, 1, 1, 1, 1, 1],
      [1, 1, 1, 1, 1, 1, 1, 1, 1]
    ];

    floodFill.run(matrix, 4, 4, 2);

    expect(floodFill.matrix).toEqual(expectedMatrix);
  });
});