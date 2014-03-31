describe("SetBitCounter - Given a number, return the number of bits set to 1 in that number", function() {
  var counter;

  beforeEach(function() {
    counter = new SetBitCounter();
  });

  it("should return 1 for 1", function() {
    expect(counter.count(1)).toEqual(1);
  });

  it("should return 1 for 2", function() {
    expect(counter.count(2)).toEqual(1);
  });

  it("should return 2 for 3", function() {
    expect(counter.count(3)).toEqual(2);
  });

  it("should return 3 for 7", function() {
    expect(counter.count(7)).toEqual(3);
  });

  it("should return 8 for 9999", function() {
    expect(counter.count(9999)).toEqual(8);
  });
});