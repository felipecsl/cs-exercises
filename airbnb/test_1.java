/*

Often, we want to encode raw IDs in our database by hiding them behind some 2-way decodeable hash. So, a URL which would have at one time been:

https://www.airbnb.com/rooms/848662
becomes
https://www.airbnb.com/rooms/nJKeY

We decode the ID 'nJKeY' to 848662 on our backend and serve the relevant content.
at some point, we start getting 404 errors from clients requesting a certain URL of the form

https://www.airbnb.com/rooms/njkey

This can happen if certain clients, email services, or url shorteners “sanitize” the url. Unfortunately, this change breaks decoding and the resource cannot be found.

To assess how big of a deal this is, we may want to recover the IDs of the targets that were 404ing.

Given a method decode(testEncStr) which will return the decoded int id if testEncStr is decodeable or will throw an exception if not, implement a new method decodeFind(String badEncStr) which takes a string and returns the decoded int id.

// you get this
public int decode(String testEncStr) throws BadIdException {
	return unHash(testEncStr);
}

// you implement this
public int decodeFind(String badEncStr) {
	// example: badEncStr = “njkey”, want to return 848662
  // decode('njkey') throws BadIdException
  // decode('nJKeY') returns 848662
}
*/

class Solution {
  public static class BadIdException extends Exception {
    public BadIdException(String message) {
      super(message);
    }
  }


  public static void main(String[] args) throws BadIdException  {
    System.out.println("Decoded to id: " + decodeFind("njkey"));
  }

  private static int unHash(String testEncStr) throws BadIdException {
    System.out.println("Testing " + testEncStr);
    if (testEncStr.equals("nJKeY")) {
      return 848662;
    } else {
      throw new BadIdException(testEncStr + " not found");
    }
  }

  // you get this
  public static int decode(String testEncStr) throws BadIdException {
    return unHash(testEncStr);
  }

  public static int decodeFind(String badEncStr) throws BadIdException  {
    return decodeFind(badEncStr, 0);
  }

  // you implement this
  public static int decodeFind(String badEncStr, int currIndex) throws BadIdException {
    if (currIndex > badEncStr.length() -1)
      return -1;

    StringBuilder upcase = new StringBuilder(badEncStr);
    StringBuilder downcase = new StringBuilder(badEncStr);
    upcase.setCharAt(currIndex, Character.toLowerCase(badEncStr.charAt(currIndex)));
    downcase.setCharAt(currIndex, Character.toUpperCase(badEncStr.charAt(currIndex)));
    String str1 = upcase.toString();
    String str2 = downcase.toString();

    try {
      return unHash(str1);
    } catch(BadIdException e) {
      return decodeFind(str1, currIndex + 1);
    }

    try {
      return unHash(str2);
    } catch(BadIdException e) {
      return decodeFind(str2, currIndex + 1);
    }

    return -1;
  }
}
