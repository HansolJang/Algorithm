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
    var n: Int = scan.nextLine().trim().toInt()
    var answer = 0
    var temp = 0
    while(n > 0) {
        if(n % 2 == 1) temp++ 
        else temp = 0
        answer = if(temp > answer) temp else answer
        n = n / 2
    }
    println("$answer")
}
