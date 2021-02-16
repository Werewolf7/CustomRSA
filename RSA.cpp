#include "RSA.h"

RSA::RSA(){}

void RSA::initialization_rsa(){
    m_numbers_for_alg.clear();

    u_ll p_tmp, q_tmmp;

    while(true){
        p_tmp = get_random_nmb(9, 200);
        if(isprime(p_tmp)){
            break;
        }
    }
    while(true){
        q_tmmp = get_random_nmb(3, 200);
        if(isprime(q_tmmp)){
            break;
        }
    }

    m_numbers_for_alg['p'] = p_tmp;
    m_numbers_for_alg['q'] = q_tmmp;
    m_numbers_for_alg['n'] = m_numbers_for_alg['p'] * m_numbers_for_alg['q'];
    m_numbers_for_alg['d'] = get_d();
    m_numbers_for_alg['e'] = get_e();
}

bool RSA::is_coprime(u_ll a, u_ll b) {
    return gcd(a, b) == 1 ? 1 : 0;
}

u_ll RSA::gcd(u_ll a, u_ll b){
    return b == 0 ? a : gcd(b, a % b);
}

u_ll RSA::get_random_nmb(u_ll&& left_boundary, u_ll&& right_boundary){
        std::random_device rd; // Источник энтропии
        std::mt19937::result_type seed = rd() ^ (  // Генератор случайных чисел (вихрь Мерсенна)
                (std::mt19937::result_type)
                std::chrono::duration_cast<std::chrono::seconds>(
                    std::chrono::system_clock::now().time_since_epoch()
                    ).count() +
                (std::mt19937::result_type)
                std::chrono::duration_cast<std::chrono::microseconds>(
                    std::chrono::high_resolution_clock::now().time_since_epoch()
                    ).count() );

        std::mt19937 gen(seed);
        std::uniform_int_distribution<> distrib(left_boundary, right_boundary); // Равномерное распределение [left_boundary, right_boundary]
    return distrib(gen);
}

u_ll RSA::get_d(){
    for(; ;){
        u_ll tmp_nmb_d = get_random_nmb(0, 200);
        if(is_coprime(tmp_nmb_d, (m_numbers_for_alg['p'] - 1) * (m_numbers_for_alg['q'] - 1))){
            return tmp_nmb_d;
        }
    }
}

u_ll RSA::get_e(){
    u_ll e = 1;
    for(; ;){
        if(isprime(e) && (e * m_numbers_for_alg['d']) % ((m_numbers_for_alg['p'] - 1) * (m_numbers_for_alg['q'] - 1)) == 1){
            break;
        }
        ++e;
    }
    return e;
}

void RSA::encryption(){
    for(u_ll i{0}; i < dt_mg->str_data.size(); ++i){
        dt_mg->encr_block_numbers[i] = binpow(dt_mg->block_numbers[i], m_numbers_for_alg['e'], m_numbers_for_alg['n']);
    }
}

void RSA::set_data_manager(DataManager* dt_mg){
    this->dt_mg = dt_mg;
}

void RSA::decryption(){
    for(u_ll i{0}; i < dt_mg->encr_block_numbers.size(); ++i){
        dt_mg->decr_block_numbers[i] = binpow(dt_mg->encr_block_numbers[i], m_numbers_for_alg['d'], m_numbers_for_alg['n']);
    }
}

RSA::~RSA(){
    delete dt_mg;
    dt_mg = nullptr;
}

DataManager* RSA::get_data_manager(){
    return dt_mg;
}

void RSA::delete_data_manager(){
    delete dt_mg;
    dt_mg = nullptr;
}

u_ll RSA::binpow(u_ll a, u_ll b, u_ll mod) {
    if (b == 0)
        return 1 % mod;
    if (b % 2 == 1)
        return (binpow (a, b - 1, mod) * a) % mod;
    else {
        return binpow ((a * a) % mod, b / 2, mod);
    }
}

bool RSA::isprime(int number){
    int count=0;

    for(int i=2; i < sqrt(number); ++i){
        if( number % i == 0){
            count++;
        }
    }
    if(number == 1|| count != 0){
        return false;
    }
    return true;
}ы

