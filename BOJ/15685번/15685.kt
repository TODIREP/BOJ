fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val n = br.readLine().toInt()
    val board = Array(101) { BooleanArray(101) { false } }
    val dx = intArrayOf(0, -1, 0, 1)
    val dy = intArrayOf(1, 0, -1, 0)
    fun curve(dir: Int, time: Int): IntArray {
        val result = mutableListOf<Int>()
        result.add(dir)
        for (it in 0 until time) {
            val size = result.size
            for (index in size - 1 downTo 0) {
                result.add((result[index] + 1) % 4)
            }
        }
        return result.toIntArray()
    }
    for (it in 0 until n) {
        val (x, y, d, g) = br.readLine().split(" ").map(String::toInt)
        var cx = y
        var cy = x
        board[cx][cy] = true
        curve(d, g).forEach {
            cx += dx[it]
            cy += dy[it]
            board[cx][cy] = true
        }
    }
    var answer = 0
    for (x in 0 until 100) {
        for (y in 0 until 100) {
            if (board[x][y] && board[x][y + 1] && board[x + 1][y] && board[x + 1][y + 1]) answer++
        }
    }
    bw.write("$answer")
    bw.close()
}