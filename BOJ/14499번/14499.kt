fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val (n, m, x, y, k) = br.readLine().split(" ").map(String::toInt)
    val board = Array(n) { IntArray(m) }
    val cube = IntArray(6) { 0 }
    for (a in 0 until n) {
        br.readLine().split(" ").forEachIndexed { b, value ->
            board[a][b] = value.toInt()
        }
    }
    var cx = x
    var cy = y
    val dx = intArrayOf(0, 0, -1, 1)
    val dy = intArrayOf(1, -1, 0, 0)
    br.readLine().split(" ").map(String::toInt).forEach loop@{
        val move = it - 1
        val nx = cx + dx[move]
        val ny = cy + dy[move]
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) return@loop
        val temp = cube[0]
        when (move) {
            0 -> {
                cube[0] = cube[3]
                cube[3] = cube[5]
                cube[5] = cube[2]
                cube[2] = temp
            }
            1 -> {
                cube[0] = cube[2]
                cube[2] = cube[5]
                cube[5] = cube[3]
                cube[3] = temp
            }
            2 -> {
                cube[0] = cube[4]
                cube[4] = cube[5]
                cube[5] = cube[1]
                cube[1] = temp
            }
            3 -> {
                cube[0] = cube[1]
                cube[1] = cube[5]
                cube[5] = cube[4]
                cube[4] = temp
            }
        }
        cx = nx
        cy = ny
        if (board[cx][cy] == 0) board[cx][cy] = cube[5]
        else {
            cube[5] = board[cx][cy]
            board[cx][cy] = 0
        }
        bw.write("${cube[0]}\n")
    }
    bw.close()
}