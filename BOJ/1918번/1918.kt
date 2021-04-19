import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val instruction = readLine()
    val stack = Stack<Char>()

    val res = StringBuilder()
    val size = instruction.length

    repeat(size) {
        when (instruction[it]) {
            in 'A'..'Z' -> res.append(instruction[it])
            '(' -> stack.add('(')
            '*', '/' -> {
                while (stack.isNotEmpty()) {
                    if ((stack.peek() == '*') or (stack.peek() == '/')) res.append(stack.pop())
                    else break
                }
                stack.push(instruction[it])
            }
            '+', '-' -> {
                while (stack.isNotEmpty()) {
                    if (stack.peek() != '(') res.append(stack.pop())
                    else break
                }
                stack.push(instruction[it])
            }
            ')' -> {
                while (stack.isNotEmpty()) {
                    if (stack.peek() != '(') res.append(stack.pop())
                    else break
                }
                stack.pop()
            }
        }
    }
    while (stack.isNotEmpty()) res.append(stack.pop())
    bw.write(res.toString())
    bw.close()
}