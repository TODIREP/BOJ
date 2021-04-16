import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun solution() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    lateinit var upper: Array<CharArray>
    lateinit var front: Array<CharArray>
    lateinit var lower: Array<CharArray>
    lateinit var back: Array<CharArray>
    lateinit var left: Array<CharArray>
    lateinit var right: Array<CharArray>
    fun rotateUpper() { // back -> right, right -> front, front -> left, left -> back
        val up = Array(3) { CharArray(3) }
        repeat(3) { x ->
            repeat(3) { y ->
                up[x][y] = upper[2 - y][x]
            }
        }
        upper = up
        val rotate = CharArray(12)
        var index = 0
        for (cur in 2 downTo 0) {
            rotate[index] = back[0][cur]
            index++
        }
        for (cur in 2 downTo 0) {
            rotate[index] = right[0][cur]
            index++
        }
        for (cur in 2 downTo 0) {
            rotate[index] = front[0][cur]
            index++
        }
        for (cur in 2 downTo 0) {
            rotate[index] = left[0][cur]
            index++
        }
        index = 0
        for (cur in 2 downTo 0) {
            right[0][cur] = rotate[index]
            index++
        }
        for (cur in 2 downTo 0) {
            front[0][cur] = rotate[index]
            index++
        }
        for (cur in 2 downTo 0) {
            left[0][cur] = rotate[index]
            index++
        }
        for (cur in 2 downTo 0) {
            back[0][cur] = rotate[index]
            index++
        }
    }

    fun rotateFront() { // upper -> right, right -> lower, lower -> left, left -> upper
        val fr = Array(3) { CharArray(3) }
        repeat(3) { x ->
            repeat(3) { y ->
                fr[x][y] = front[2 - y][x]
            }
        }
        front = fr
        val rotate = CharArray(12)
        var index = 0
        repeat(3) {
            rotate[index] = upper[2][it]
            index++
        }
        repeat(3) {
            rotate[index] = right[it][0]
            index++
        }
        for (cur in 2 downTo 0) {
            rotate[index] = lower[0][cur]
            index++
        }
        for (cur in 2 downTo 0) {
            rotate[index] = left[cur][2]
            index++
        }
        index = 0
        repeat(3) {
            right[it][0] = rotate[index]
            index++
        }
        for (cur in 2 downTo 0) {
            lower[0][cur] = rotate[index]
            index++
        }
        for (cur in 2 downTo 0) {
            left[cur][2] = rotate[index]
            index++
        }
        repeat(3) {
            upper[2][it] = rotate[index]
            index++
        }
    }

    fun rotateLower() { // front -> right, right -> back, back -> left, left -> front
        val lw = Array(3) { CharArray(3) }
        repeat(3) { x ->
            repeat(3) { y ->
                lw[x][y] = lower[2 - y][x]
            }
        }
        lower = lw
        val rotate = CharArray(12)
        var index = 0
        repeat(3) {
            rotate[index] = front[2][it]
            index++
        }
        repeat(3) {
            rotate[index] = right[2][it]
            index++
        }
        repeat(3) {
            rotate[index] = back[2][it]
            index++
        }
        repeat(3) {
            rotate[index] = left[2][it]
            index++
        }
        index = 0
        repeat(3) {
            right[2][it] = rotate[index]
            index++
        }
        repeat(3) {
            back[2][it] = rotate[index]
            index++
        }
        repeat(3) {
            left[2][it] = rotate[index]
            index++
        }
        repeat(3) {
            front[2][it] = rotate[index]
            index++
        }
    }

    fun rotateBack() { // upper -> left, left -> lower, lower -> right, right -> upper
        val bk = Array(3) { CharArray(3) }
        repeat(3) { x ->
            repeat(3) { y ->
                bk[x][y] = back[2 - y][x]
            }
        }
        back = bk
        val rotate = CharArray(12)
        var index = 0
        for (cur in 2 downTo 0) {
            rotate[index] = upper[0][cur]
            index++
        }
        repeat(3) {
            rotate[index] = left[it][0]
            index++
        }
        repeat(3) {
            rotate[index] = lower[2][it]
            index++
        }
        for (cur in 2 downTo 0) {
            rotate[index] = right[cur][2]
            index++
        }
        index = 0
        repeat(3) {
            left[it][0] = rotate[index]
            index++
        }
        repeat(3) {
            lower[2][it] = rotate[index]
            index++
        }
        for (cur in 2 downTo 0) {
            right[cur][2] = rotate[index]
            index++
        }
        for (cur in 2 downTo 0) {
            upper[0][cur] = rotate[index]
            index++
        }
    }

    fun rotateLeft() { // upper -> front, front -> lower, lower -> back, back -> upper
        val lf = Array(3) { CharArray(3) }
        repeat(3) { x ->
            repeat(3) { y ->
                lf[x][y] = left[2 - y][x]
            }
        }
        left = lf
        val rotate = CharArray(12)
        var index = 0
        repeat(3) {
            rotate[index] = upper[it][0]
            index++
        }
        repeat(3) {
            rotate[index] = front[it][0]
            index++
        }
        repeat(3) {
            rotate[index] = lower[it][0]
            index++
        }
        for (cur in 2 downTo 0) {
            rotate[index] = back[cur][2]
            index++
        }
        index = 0
        repeat(3) {
            front[it][0] = rotate[index]
            index++
        }
        repeat(3) {
            lower[it][0] = rotate[index]
            index++
        }
        for (cur in 2 downTo 0) {
            back[cur][2] = rotate[index]
            index++
        }
        repeat(3) {
            upper[it][0] = rotate[index]
            index++
        }
    }

    fun rotateRight() { // upper -> back, back -> lower, lower -> front, front -> upper
        val rt = Array(3) { CharArray(3) }
        repeat(3) { x ->
            repeat(3) { y ->
                rt[x][y] = right[2 - y][x]
            }
        }
        right = rt
        val rotate = CharArray(12)
        var index = 0
        for (cur in 2 downTo 0) {
            rotate[index] = upper[cur][2]
            index++
        }
        repeat(3) {
            rotate[index] = back[it][0]
            index++
        }
        for (cur in 2 downTo 0) {
            rotate[index] = lower[cur][2]
            index++
        }
        for (cur in 2 downTo 0) {
            rotate[index] = front[cur][2]
            index++
        }
        index = 0
        repeat(3) {
            back[it][0] = rotate[index]
            index++
        }
        for (cur in 2 downTo 0) {
            lower[cur][2] = rotate[index]
            index++
        }
        for (cur in 2 downTo 0) {
            front[cur][2] = rotate[index]
            index++
        }
        for (cur in 2 downTo 0) {
            upper[cur][2] = rotate[index]
            index++
        }
    }

    val n = readLine().toInt()
    repeat(n) {
        upper = Array(3) { CharArray(3) { 'w' } }
        front = Array(3) { CharArray(3) { 'r' } }
        lower = Array(3) { CharArray(3) { 'y' } }
        back = Array(3) { CharArray(3) { 'o' } }
        left = Array(3) { CharArray(3) { 'g' } }
        right = Array(3) { CharArray(3) { 'b' } }
        readLine().toInt()
        readLine().split(" ").forEach { cur ->
            when (cur[0]) {
                'U' -> {
                    rotateUpper()
                    if (cur[1] == '-') {
                        rotateUpper()
                        rotateUpper()
                    }
                }
                'D' -> {
                    rotateLower()
                    if (cur[1] == '-') {
                        rotateLower()
                        rotateLower()
                    }
                }
                'F' -> {
                    rotateFront()
                    if (cur[1] == '-') {
                        rotateFront()
                        rotateFront()
                    }
                }
                'B' -> {
                    rotateBack()
                    if (cur[1] == '-') {
                        rotateBack()
                        rotateBack()
                    }
                }
                'L' -> {
                    rotateLeft()
                    if (cur[1] == '-') {
                        rotateLeft()
                        rotateLeft()
                    }
                }
                'R' -> {
                    rotateRight()
                    if (cur[1] == '-') {
                        rotateRight()
                        rotateRight()
                    }
                }
            }
        }
        repeat(3) { x ->
            repeat(3) { y ->
                bw.write("${upper[x][y]}")
            }
            bw.write("\n")
        }
    }
    bw.close()
}

fun main() {
    solution()
}