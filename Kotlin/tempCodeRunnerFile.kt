private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles
  
fun main(args: Array<String>) {
  var n = readInt();
  var a = readInts();
  var x = -1;
  var y = -1;
  var z = -1;
  for (i in 0 until n) {
    if (x == -1) {
      x = i + 1;
    }
    if (y == -1) {
      if (a.elementAt(x - 1) != a.elementAt(i)) {
        y = i + 1;
      }
    }
    if (z == -1) {
      if (a.elementAt(x - 1) != a.elementAt(i) && a.elementAt(y - 1) != a.elementAt(i)) {
        z = i + 1;
      }
    }
  }
  if (z == -1 || y == -1 || x == -1) {
    println("-1 -1 -1");
  } else {
    println("$x $y $z");
  }
}