fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val (n, m) = br.readLine().split(" ").map(String::toInt)
    val arr = Array(n) { IntArray(m) }
    for (x in 0 until n) {
        val input = br.readLine()
        for (y in 0 until m) arr[x][y] = input[y] - '0'
    }
    for (x in 1 until n) for (y in 1 until m) if (arr[x][y] == 1) arr[x][y] = arr[x - 1][y].coerceAtMost(arr[x][y - 1].coerceAtMost(arr[x - 1][y - 1])) + 1
    var ans = 0
    for (x in 0 until n) for (y in 0 until m) ans = ans.coerceAtLeast(arr[x][y])
    bw.write("${ans * ans}")
    bw.close()
}