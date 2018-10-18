import java.io.*
import java.math.*
import java.security.*
import java.text.*
import java.util.*
import java.util.concurrent.*
import java.util.function.*
import java.util.regex.*
import java.util.stream.*
import kotlin.collections.*
import kotlin.comparisons.*
import kotlin.io.*
import kotlin.jvm.*
import kotlin.jvm.functions.*
import kotlin.jvm.internal.*
import kotlin.ranges.*
import kotlin.sequences.*
import kotlin.text.*

fun main(args: Array<String>) {
    val scan = Scanner(System.`in`)

    val arr = Array<Array<Int>>(6, { Array<Int>(6, { 0 }) })

    for (i in 0 until 6) {
        arr[i] = scan.nextLine().split(" ").map{ it.trim().toInt() }.toTypedArray()
    }

    var answer = -100
    var temp = 0
    for(i in 0..3) {
        for(j in 0..3) {
            temp = 0
            for(k in 0..2) {
                for(l in 0..2) {
                    if(k == 1 && l != 1) continue
                    temp = temp + arr[i + k][j + l]
                }
            }
            answer = if(temp > answer) temp else answer
        }
    }
    println("$answer")
}
