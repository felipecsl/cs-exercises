describe("FourWayEdgeFill", function() {
  var edgeFill;

  beforeEach(function() {
    edgeFill = new FourWayEdgeFill();
  });

  it("should edge fill a matrix", function() {
    var printMatrix = function(matrixToPrint) {
      for(var i = 0; i < matrixToPrint.length; i++) {
        for(var j = 0; j < matrixToPrint[i].length; j++) {
          document.write(matrixToPrint[i][j] + " ");
        }
        document.write("<br>");
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
      [1, 1, 2, 2, 2, 2, 2, 1, 1],
      [1, 2, 0, 0, 0, 0, 0, 2, 1],
      [1, 2, 0, 0, 0, 0, 0, 2, 1],
      [1, 2, 0, 0, 0, 0, 0, 2, 1],
      [1, 2, 0, 0, 0, 0, 0, 2, 1],
      [1, 2, 0, 0, 0, 0, 0, 2, 1],
      [1, 1, 2, 2, 2, 2, 2, 1, 1],
      [1, 1, 1, 1, 1, 1, 1, 1, 1]
    ];

    edgeFill.run(matrix, 4, 4, 2);

    expect(edgeFill.matrix).toEqual(expectedMatrix);
  });
});