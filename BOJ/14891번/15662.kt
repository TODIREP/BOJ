fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    val wheel = Array(t) { BooleanArray(8) { false } }
    for (x in 0 until t) {
        br.readLine().forEachIndexed { y, value -> wheel[x][y] = value == '1' }
    }
    val k = br.readLine().toInt()
    val turn = IntArray(t) { 0 }
    for (it in 0 until k) {
        val (i, d) = br.readLine().split(" ").map(String::toInt)
        turn[i - 1] = d
        for (index in i - 2 downTo 0) {
            if (wheel[index][2] != wheel[index + 1][6]) turn[index] = -turn[index + 1]
        }
        for (index in i until t) {
            if (wheel[index][6] != wheel[index - 1][2]) turn[index] = -turn[index - 1]
        }
        for (index in 0 until t) {
            when (turn[index]) {
                0 -> continue
                1 -> {
                    val temp = wheel[index][7]
                    for (cur in 7 downTo 1) wheel[index][cur] = wheel[index][cur - 1]
                    wheel[index][0] = temp
                }
                -1 -> {
                    val temp = wheel[index][0]
                    for (cur in 0 until 7) wheel[index][cur] = wheel[index][cur + 1]
                    wheel[index][7] = temp
                }
            }
            turn[index] = 0
        }
    }
    var answer = 0
    for (it in 0 until t) {
        if (wheel[it][0]) answer++
    }
    bw.write("$answer")
    bw.close()
}