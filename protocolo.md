# Protocolo de comunicação com os robôs

## Computador -> Rádio

Byte | Função              
-----|---------------------
  1  | Time     (4 bits)
  "  | Endereço (4 bits)   
  2  | Comando     
  3  | Velocidade x        
  4  | Velocidade y        
  5  | Velocidade angular  
  6  | Ângulo do chute  (6 bits)
  "  | Potência (2 bits)
  ?  | CRC 



## Radio -> Chicó

Byte | Função              
-----|---------------------
  1  | Time     (4 bits)
  "  | Endereço (4 bits)   
  2  | Comando     
  3  | Velocidade x        
  4  | Velocidade y        
  5  | Velocidade angular  
  6  | Ângulo do chute  (6 bits)
  "  | Potência (2 bits)
  ?  | CRC

  
  
## Chicó -> computador

Byte | Função              
-----|---------------------
  1  | Endereço (3 bits)   
  "  | Comando  (5 bits)   
  2  | Status da bateria        
  3  | Presença da bola  
  4  | Nº de pacotes perdidos
  ?  | CRC


precisamos fazer um CRC nosso, ficou decidido em reunião 
que  nosso CRC é uma redundância  necessária 
