   #include "Hangman.h"

Hangman::Hangman() {
            setHangmanan();
    }

    // getters

    const std::string & Hangman::getDescription() const{
        return this->m_description;
    }
    const std::string & Hangman::getWord() const{
        return this->m_word;
    }
    const std::string & Hangman::getAttempts() const{
        return this->m_attempts;
    }
    const std::string & Hangman::getInfo() const{
        return this->m_info;
    }
    unsigned int Hangman::getLives() const{
        return this->m_lives;
    }
    const bool Hangman::hasEnded() const{
        return this->m_isEnded;
    }

    // setters

    void Hangman::setInfo(const std::string & newInfo){
        this->m_info = newInfo;
    }
    void Hangman::updateInfo(int i, char a){
        this->m_info[i] = a;
    }
    void Hangman::setDescription(const std::string & newDescription){
        this->m_description = newDescription;
    }
    void Hangman::setAttemps(const std::string & newAttempts){
        this->m_attempts =newAttempts;
    }
    void Hangman::setAttemps(const char & a){
        this->m_attempts +=a;
    }
    void Hangman::setLives(unsigned int newLives){
        this->m_lives = newLives;
    }
    void Hangman::setWord(const std::string & newWord){
        this->m_word = newWord;
    }
    void Hangman:: setStatus(const bool a= false){
        this->m_isEnded = a;
    }
    // game logic

    void Hangman::printInfo(){
        std::cout<< "Description: "<< this->getDescription()<< std::endl;
        std::cout<< "Failed attempts: "<< this->getAttempts() <<std::endl;
        std::cout<< "Remaining lives: "<< this->getLives()<< std::endl;
        for (size_t i = 0; i < m_info.size(); i++)
        {
            std::cout << m_info[i]<<' ';
        }
        std::cout<<std::endl;
    }

    void Hangman::setHangmanan(){
        std::cout<< "Please enter a word, followed by brief desctiption on a new line \n";
        std::string word{""};
        std::string description{""};
        std::string info{""};
       
        std::cin >> word;
        this->setWord(word);

        std::getline(std::cin, description);
        this->setDescription(description);

        for (size_t i = 0; i < this->getWord().size(); i++)
        {
            info += '_';
        }
        this->setInfo(info);
        setLives();
        setStatus();
    }

    void Hangman::checkTrial(const std::string & trial){
        for(auto & a : trial){
            bool isFound{false};
            for (auto letter : this->getAttempts())
            {
                if (letter == a)
                {
                    std::cout << "You tried this and were wrong\n\n";
                    break;
                } 
            }
    
            for (size_t i = 0; i < getWord().size(); i++)
            {
                if (getWord()[i] == a)
                {
                    updateInfo(i, a);
                    isFound = true;
                    std:: cout << "Found! \n\n"<<std::endl;
                }
            }
            if(!isFound){
                setLives(getLives()-1);
                setAttemps(a);
                std:: cout << "Not Found!\n\n"<<std::endl;
            }
            if(getLives() == 0){
                std::cout<< "\n You died! \n"<<std::endl;
            }
        }
    }
    
    bool Hangman::checkWin(){
        return getWord() == getInfo();
    }
    
    void Hangman::play(){
        std::string trial{""};
        std::string message{"Enter your guess or -1 for exit \n"};
        do{
            std::cout << message;
            if (trial == "-1") break;
            if (trial == "") continue;
            
            this->checkTrial(trial);
            if (this->checkWin() || this->getLives() == 0)
            {   
                setStatus(true);
                break;
            }
            this->printInfo(); 
        }
        while (std::getline(std::cin,trial));
    }
    void Hangman::playNew(){
        this->setHangmanan();
        play();
    }