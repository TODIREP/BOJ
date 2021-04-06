import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun solution() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val (n, m, k) = readLine().split(" ").map(String::toInt)
    val target = Array(n) { readLine().split(" ").map(String::toInt).toIntArray() }
    val oper = Array(k) { readLine().split(" ").map(String::toInt).toIntArray() }

    fun rotateArr(myArr: Array<IntArray>, sx: Int, sy: Int, ex: Int, ey: Int) {
        val count = (ex - sx + 1).coerceAtLeast(ey - sy + 1) / 2
        val groups = mutableListOf<MutableList<Int>>()

        repeat(count) { level ->
            val group = mutableListOf<Int>()
            for (index in sy + level until ey - level) {
                group.add(myArr[sx + level][index])
            }
            for (index in sx + level until ex - level) {
                group.add(myArr[index][ey - level])
            }
            for (index in ey - level downTo sy + level + 1) {
                group.add(myArr[ex - level][index])
            }
            for (index in ex - level downTo sx + level + 1) {
                group.add(myArr[index][sy + level])
            }
            groups.add(group)
        }
        repeat(count) { level ->
            val group = groups[level]
            val size = group.size
            var current = size - 1

            for (index in sy + level until ey - level) {
                myArr[sx + level][index] = group[current]
                current = (current + 1) % size
            }
            for (index in sx + level until ex - level) {
                myArr[index][ey - level] = group[current]
                current = (current + 1) % size
            }
            for (index in ey - level downTo sy + level + 1) {
                myArr[ex - level][index] = group[current]
                current = (current + 1) % size
            }
            for (index in ex - level downTo sx + level + 1) {
                myArr[index][sy + level] = group[current]
                current = (current + 1) % size
            }
        }
    }

    val opers = IntArray(k)
    repeat(k) {
        opers[it] = it
    }
    val check = BooleanArray(k) { false }
    val array = IntArray(k) { -1 }

    var answer = 1000000000
    fun search(cnt: Int) {
        if (cnt == k) {
            var curRowSum = 100000000
            val myArr = Array(n) { IntArray(m) }
            repeat(n) { p ->
                repeat(m) { q ->
                    myArr[p][q] = target[p][q]
                }
            }
            repeat(k) {
                val (x, y, l) = oper[array[it]]
                rotateArr(myArr, x - l - 1, y - l - 1, x + l - 1, y + l - 1)
            }
            repeat(n) {
                curRowSum = curRowSum.coerceAtMost(myArr[it].sum())
            }
            answer = answer.coerceAtMost(curRowSum)
            return
        }
        repeat(k) loop@ {
            if (check[it]) return@loop
            check[it] = true
            array[cnt] = opers[it]
            search(cnt + 1)
            check[it] = false
        }
    }
    search(0)
    bw.write("$answer")
    bw.close()
}
fun main() {
    solution()
}