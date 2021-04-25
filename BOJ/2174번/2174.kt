data class Stat(var x: Int, var y: Int, var dir: Int)
fun getDir(direction: String): Int {
    return when (direction) {
        "E" -> 0
        "N" -> 1
        "W" -> 2
        else -> 3 // "S"
    }
}
fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val (a, b) = br.readLine().split(" ").map(String::toInt)
    val (n, m) = br.readLine().split(" ").map(String::toInt)
    val world = Array(a) { IntArray(b) { -1 } }

    val robots: Array<Stat?> = arrayOfNulls(n)
    repeat(n) {
        val (x, y, d) = br.readLine().split(" ")
        val cx = x.toInt() - 1
        val cy = y.toInt() - 1
        robots[it] = Stat(cx, cy, getDir(d))
        world[cx][cy] = it
    }
    var responseCode = 0
    var attacker = -1
    var victim = -1
    // 0 : OK
    // 1 : Robot X crashes into the wall
    // 2 : Robot X crashes into robot Y
    val dx = intArrayOf(1, 0, -1, 0)
    val dy = intArrayOf(0, 1, 0, -1)
    for (play in 0 until m) {
        val (r, d, t) = br.readLine().split(" ")
        val robot = r.toInt() - 1
        val turn = t.toInt()
        val current = robots[robot]!!
        val rx = current.x
        val ry = current.y
        val rd = current.dir

        when (d) {
            // 왼쪽으로 t번 회전 == t % 4번 회전
            "L" -> robots[robot]!!.dir = (rd + (turn % 4)) % 4
            // 오른쪽으로 t번 회전 == t % 4 번 회전
            "R" -> robots[robot]!!.dir = (rd - (turn % 4) + 4) % 4
            // 앞으로 한 칸 움직임. == 앞으로 t칸 움직임
            // 1칸 앞부터 t칸 까지 로봇이 있으면 충돌
            // t칸 이동 시 땅을 벗어나면 벽에 충돌
            else -> {
                var valid = true
                for (move in 1..turn) {
                    val mx = rx + dx[rd] * move
                    val my = ry + dy[rd] * move
                    if ((mx < 0) or (mx >= a) or (my < 0) or (my >= b)) {
                        valid = false
                        attacker = robot + 1
                        responseCode = 1
                        break
                    }
                    if (world[mx][my] != -1) {
                        valid = false
                        attacker = robot + 1
                        victim = world[mx][my] + 1
                        responseCode = 2
                        break
                    }
                }
                if (valid) {
                    val nx = rx + dx[rd] * turn
                    val ny = ry + dy[rd] * turn
                    world[rx][ry] = -1
                    robots[robot]!!.x = nx
                    robots[robot]!!.y = ny
                    world[nx][ny] = robot
                }
            }
        }
        if (responseCode != 0) break
    }
    bw.write(
        when (responseCode) {
            0 -> "OK"
            1 -> "Robot $attacker crashes into the wall"
            else -> "Robot $attacker crashes into robot $victim"
        }
    )
    bw.close()
}