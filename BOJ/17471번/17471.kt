import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*
import kotlin.math.absoluteValue

fun solution() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val n = readLine().toInt()
    val people = readLine().split(" ").map(String::toInt).toIntArray()
    val link = Array(n) { mutableListOf<Int>() }

    repeat(n) {
        val input = readLine().split(" ").map(String::toInt).toIntArray()
        val next = input[0]
        for (index in 1 until next + 1) {
            link[it].add(input[index] - 1)
        }
    }

    val check = BooleanArray(n) { false }
    val party = IntArray(n)
    var answer = 100000000

    fun search(cnt: Int) {
        if ((cnt <= n / 2) and (cnt > 0)) {
            val vis = IntArray(n) { -1 }
            fun bfs(start: Int, number: Int) {
                val queue: Queue<Int> = LinkedList()
                vis[start] = number
                queue.add(start)
                while (queue.isNotEmpty()) {
                    val cur = queue.remove()
                    for (nxt in link[cur]) {
                        if ((check[nxt] == check[cur]) and (vis[nxt] == -1)) {
                            vis[nxt] = number
                            queue.add(nxt)
                        }
                    }
                }
            }

            var valid = true
            bfs(party[0], 0)
            var num = 1
            repeat(n) {
                if (vis[it] == -1) {
                    if (num == 2) valid = false
                    bfs(it, num)
                    num++
                }
            }

            if (valid) {
                var aParty = 0
                var bParty = 0

                repeat(n) {
                    when (vis[it]) {
                        0 -> aParty += people[it]
                        1 -> bParty += people[it]
                    }
                }
                answer = answer.coerceAtMost((aParty - bParty).absoluteValue)
            }
        }
        if (cnt == n / 2) return

        repeat(n) loop@ {
            if (check[it]) return@loop
            check[it] = true
            party[cnt] = it
            search(cnt + 1)
            check[it] = false
        }
    }
    search(0)
    bw.write("${if (answer == 100000000) -1 else answer}")
    bw.close()
}
fun main() {
    solution()
}