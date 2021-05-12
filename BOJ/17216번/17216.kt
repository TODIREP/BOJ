fun main() = with(System.`in`.bufferedReader()) {
    val bw = System.out.bufferedWriter()
    val n = readLine().toInt()
    val array = readLine().split(" ").map(String::toInt).toIntArray()
    val result = Array(n) { IntArray(2) { 0 } }
    result[0] = intArrayOf(1, array[0])
    var answer = result[0][1]
    for (it in 1 until n) {
        var before = it
        for (prev in it - 1 downTo 0) {
            if (array[prev] > array[it] && result[prev][1] > result[before][1]) before = prev
        }
        result[it] = intArrayOf(result[before][0] + 1, result[before][1] + array[it])
        answer = answer.coerceAtLeast(result[it][1])
    }
    bw.write("$answer")
    bw.close()
}