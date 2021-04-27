fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val wheel = Array(4) { BooleanArray(8) { false } }
    for (x in 0 until 4) {
        br.readLine().forEachIndexed { y, value -> wheel[x][y] = value == '1' }
    }
    val k = br.readLine().toInt()
    val turn = IntArray(4) { 0 }
    for (it in 0 until k) {
        val (i, d) = br.readLine().split(" ").map(String::toInt)
        turn[i - 1] = d
        for (index in i - 2 downTo 0) {
            if (wheel[index][2] != wheel[index + 1][6]) turn[index] = -turn[index + 1]
        }
        for (index in i until 4) {
            if (wheel[index][6] != wheel[index - 1][2]) turn[index] = -turn[index - 1]
        }
        for (index in 0 until 4) {
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
    val answer = StringBuilder()
    for (it in 0 until 4) {
        answer.append(
            when (wheel[it][0]) {
                true -> "1"
                false -> "0"
            }
        )
    }
    bw.write("${Integer.parseInt(answer.toString().reversed(), 2)}")
    bw.close()
}