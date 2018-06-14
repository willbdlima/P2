#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu(){
	
	printf("\nInserir reservas              1\n");
	printf("Alterar reservas              2\n");
	printf("Excluir reservas              3\n");
	printf("Excluir todas reservas        4\n");
	printf("Consultar reserva             5\n");
	printf("Visualizar todas reservas     6\n");
	printf("Sair                          7\n");
	printf("\nDigite o numero correspondente: ");
	
}

main(){
	
	struct cadastro
	{
		char nome[50];
		int ativador, rg, cpf, qtdpes, telefone, dia, mes;
		
	};
	
	FILE *pont_arq;
  	char texto_str[250];
  	char* token;
	
	struct cadastro reserva[30];
	char login[20];
	int menuop, i=0, n, nn, cont=0, x=0;
	
	pont_arq=fopen("Reservas.txt", "r");
	
	while(fgets(texto_str, 250, pont_arq)!=NULL){
		
		token = strtok(texto_str, "@");
		
			while(token!=NULL){
        
      			if(x==0){
      				
      				strcpy(reserva[i].nome,token);
        			x++;
        			
        		}else if(x==1){
        			
        			reserva[i].rg=atoi(token);
        			x++;
        			
        		}else if(x==2){
        			
        			reserva[i].cpf=atoi(token);
        			x++;
        			
				}else if(x==3){
					
					reserva[i].telefone=atoi(token);
        			x++;
        			
				}else if(x==4){
					
					reserva[i].qtdpes=atoi(token);
        			x++;
					
				}else if(x==5){
					
					reserva[i].mes=atoi(token);
        			x++;
        			
				}else if(x==6){
					
					reserva[i].dia=atoi(token);
        			x++;
        			
				}else if(x==7){
					
					reserva[i].ativador=atoi(token);
        			x++;
        			
				}//if adquirir as linhas
				
				token=strtok(NULL, "@");
				
			}//while
			
			x=0;
			i++;
		}
		
		fclose(pont_arq);
		
		
	printf("Bem-vindo ao sistema de reservas de mesas.\n\n");
	printf("---- Restaurante Hot Plate ----\n");
	printf("\nDigite seu nome de login: ");
	scanf("%s",&login);
	
	system("cls");
	
	printf("O que deseja fazer %s?\n", login);
	menu();
	scanf("%d",&menuop);
	
	while(menuop!=7){
                    
                switch(menuop){
                         
                        case 1:
									
	                          n=1;
									
                              while(n==1){
                              
                              system("cls");
                              
                              printf("Digite o numero da mesa: ");
                              scanf("%d",&i);
                              printf("\n"); 
                                     
                                     i=i-1;
                                     
                                     		if(i<0||i>29){
                                                     
                                     		printf("Mesa indisponivel. Nossas reservas estao disponiveis para mesas de 1 a 30.\n");
                                     
                                           }else if(reserva[i].ativador==1){
                                                   
                                                   printf("Mesa ja reservada.\n");
                                                   
                                           }else{
                                                 
                                                   printf("Nome completo: ");
										           scanf(" %[^\n]",&reserva[i].nome);
								
										           printf("RG (sem pontuacao): ");
										           scanf("%d",&reserva[i].rg);
								
										           printf("CPF (sem pontuacao): ");
										           scanf("%d",&reserva[i].cpf);
									
										           printf("Telefone para contato (sem pontuacao): ");
										           scanf("%d",&reserva[i].telefone);
								
										           printf("Quantidade de pessoas por mesa (2 a 8 pessoas): ");
									               scanf("%d",&reserva[i].qtdpes);
										           
                                                           while(reserva[i].qtdpes<2||reserva[i].qtdpes>8){
                                                                                                      
                                                                       printf("Quantidade incorreta. Reservas de 2 a 8 pessoas. Digite novamene: ");
                                                                       scanf("%d",&reserva[i].qtdpes);
                                                                                                      
                                                           }//while para quantidade de pessoas
									
										           printf("Mes (de 1 a 12): ");
										           scanf("%d",&reserva[i].mes);
										           
                                                           while(reserva[i].mes<1||reserva[i].mes>12){
                                                                                                      
                                                                       printf("Erro. Mes inexistente. Digite novamente: ");
                                                                       scanf("%d",&reserva[i].mes);
                                                                                                      
                                                           }//while para mes inexistente
                                                           
                                                   printf("Dia: ");
		                                           scanf("%d",&reserva[i].dia);
		                                           
                                                        
                                                                       
                                                            if(reserva[i].mes==4||reserva[i].mes==6||reserva[i].mes==9||reserva[i].mes==11){
                                                                                  
                                                                            while(reserva[i].dia<=0||reserva[i].dia>=31){
                                                                                                    
                                                                                    printf("Erro. Para o mes %d nao existe o dia %d. Digite novamente: ",reserva[i].mes,reserva[i].dia);
                                                                                    scanf("%d",&reserva[i].dia);
                                                                                                    
                                                                            }//while para dia 31
                                                                                            
                                                            }else if(reserva[i].mes==2){
                                                                                            
                                                                            while(reserva[i].dia<=0||reserva[i].dia>=30){
                                                                                                                                       
                                                                                    printf("Erro. Para o mes %d nao existe o dia %d. Digite novamente: ",reserva[i].mes,reserva[i].dia);
                                                                                    scanf("%d",&reserva[i].dia);
                                                                                                    
                                                                            }//while para fev 29+
                                                                                                                        
                                                            }else{
                                                            	
                                                            				while(reserva[i].dia<=0||reserva[i].dia>=32){
                                                                                                                                       
                                                                                    printf("Erro. Para o mes %d nao existe o dia %d. Digite novamente: ",reserva[i].mes,reserva[i].dia);
                                                                                    scanf("%d",&reserva[i].dia);
                                                                                                    
                                                                            }//while outros meses
                                                                            
															}//if para dia incorretos
															
													reserva[i].ativador = 1;
										           
                                           }//if do ativador
                                           
									
									       printf("\nDeseja realizar outra reserva?\n\n");
									       printf("Sim          1\n");
									       printf("Nao          2\n\n");
									       printf("Digite o comando correspondente: ");
									       scanf("%d",&n);
									       
									       while(n<1||n>2){
                                                           
                                                           system("cls");
                                                        
                                                        printf("Comando inexistente.\n");
                                                        printf("\nDeseja realizar outra reserva?\n\n");
									                    printf("Sim          1\n");
									                    printf("Nao          2\n\n");
									                    printf("Digite o comando correspondente: ");
									                    scanf("%d",&n);
									                    printf("\n");
									                    
									                    system("cls");
                                                        
                                           }//while add reserva comando errado.
                                           
                                           		if(n==2){
                                           			
                                           		system("cls");
                                           	
										   		printf("Reserva(s) gravada(s) com sucesso.\n\n");
										   		
										   		}
                                           
                                     }//while pra add mais reservas   
                                     break;
                                     
                            case 2:
								
								n=1;
									
                              	while(n==1){
                              
                              	system("cls");
								
								printf("Digite o numero da mesa que deseja alterar a reserva: ");
								scanf("%d",&nn);
								
								i = nn-1;
								
								if(reserva[i].ativador!=1){
																		
									printf("\nNao ha reserva gravada neste numero.\n");
									
								}else{
									
									printf("\nReserva %d\n",nn);
									printf("\n%s\n",reserva[i].nome);
									printf("RG: %d\n",reserva[i].rg);
									printf("CPF: %d\n",reserva[i].cpf);
									printf("Telefone: %d\n",reserva[i].telefone);
									printf("%d pessoas por mesa\n",reserva[i].qtdpes);
									printf("Data: %d/%d\n\n",reserva[i].dia,reserva[i].mes);
									
									
									printf("O que voce deseja alterar %s?\n",login);
									printf("\nNome                  1\n");
									printf("RG                    2\n");
									printf("CPF                   3\n");
									printf("Telefone de contato   4\n");
									printf("Pessoas por mesa      5\n");
									printf("Mes                   6\n");
									printf("Dia                   7\n");
									printf("Todas informacoes     8\n");
									printf("\nDigite o numero correspondente: ");
									scanf("%d",&n);
									
										switch(n){
											
												case 1:
													
													printf("\nNome atual: %s\n",reserva[i].nome);
													printf("Novo nome: ");
													scanf(" %[^\n]",&reserva[i].nome);
													
													system("cls");
													
													printf("Nome alterado com sucesso.\n");
													
													break;
													
												case 2:
													
													printf("\nRG atual: %d\n",reserva[i].rg);
													printf("Novo RG (sem pontuacao): ");
													scanf("%d",&reserva[i].rg);
													
													system("cls");
													
													printf("RG alterado com sucesso.\n");
													
													break;
													
												case 3:
													
													printf("\nCPF atual: %d\n",reserva[i].cpf);
													printf("Novo CPF (sem pontuacao): ");
													scanf("%d",&reserva[i].cpf);
													
													system("cls");
													
													printf("CPF alterado com sucesso.\n");
													
													break;
													
												case 4:
													
												printf("\nTelefone de contato atual: %d\n",reserva[i].telefone);
												printf("Novo telefone de contato (sem pontuacao): ");
												scanf("%d",&reserva[i].telefone);
													
												system("cls");
													
												printf("Telefone de contato alterado com sucesso.\n");
													
													break;
													
												case 5:
													
													printf("\nQuantidade de pessoas atual: %d\n",reserva[i].qtdpes);
													printf("Nova quantidade de pessoas: ");
													scanf("%d",&reserva[i].qtdpes);
													
													system("cls");
													
													printf("Quantidade de pessoas alterada com sucesso.\n");
													
													break;
												
												case 6:
													
													printf("\nMes atual: %d\n",reserva[i].qtdpes);
													printf("Novo mes (de 1 a 12): ");
													scanf("%d",&reserva[i].mes);
													
													while(reserva[i].mes<1||reserva[i].mes>12||reserva[i].mes==4&&reserva[i].dia>30||reserva[i].mes==6&&reserva[i].dia>30||reserva[i].mes==9&&reserva[i].dia>30||reserva[i].mes==11&&reserva[i].dia>30||reserva[i].mes==2&&reserva[i].dia>29){
                                                                                                      
                                                                       printf("Erro. Mes inexistente ou dia inexistente para o mes. Digite novamente: ");
                                                                       scanf("%d",&reserva[i].mes);
                                                                                                      
                                                    }//while para mes inexistente
                                                    
                                                    system("cls");
                                                    
                                                    printf("Mes alterado com sucesso.\n");
                                                    
                                                    break;
                                                
                                                case 7:
                                                	
                                                	printf("\nDia atual: %d\n",reserva[i].dia);
													printf("Novo dia: ");
													scanf("%d",&reserva[i].dia);
													
													if(reserva[i].mes==4||reserva[i].mes==6||reserva[i].mes==9||reserva[i].mes==11){
                                                                                  
                                                                            while(reserva[i].dia<=0||reserva[i].dia>=31){
                                                                                                    
                                                                                    printf("Erro. Para o mes %d nao existe o dia %d. Digite novamente: ",reserva[i].mes,reserva[i].dia);
                                                                                    scanf("%d",&reserva[i].dia);
                                                                                                    
                                                                            }//while para dia 31
                                                                                            
                                                            }else if(reserva[i].mes==2){
                                                                                            
                                                                            while(reserva[i].dia<=0||reserva[i].dia>=30){
                                                                                                                                       
                                                                                    printf("Erro. Para o mes %d nao existe o dia %d. Digite novamente: ",reserva[i].mes,reserva[i].dia);
                                                                                    scanf("%d",&reserva[i].dia);
                                                                                                    
                                                                            }//while para fev 29+
                                                                                                                        
                                                            }else{
                                                            	
                                                            				while(reserva[i].dia<=0||reserva[i].dia>=32){
                                                                                                                                       
                                                                                    printf("Erro. Para o mes %d nao existe o dia %d. Digite novamente: ",reserva[i].mes,reserva[i].dia);
                                                                                    scanf("%d",&reserva[i].dia);
                                                                                                    
                                                                            }//while outros meses
                                                                            
															}//if para dia incorretos
													
													system("cls");
													
													printf("Dia alterado com sucesso.\n");
                                                	
                                                	break;
													
													case 8:
														
													system("cls");
														
													printf("Nome completo: ");
										           scanf("%s",&reserva[i].nome);
								
										           printf("RG (sem pontuacao): ");
										           scanf("%d",&reserva[i].rg);
								
										           printf("CPF (sem pontuacao): ");
										           scanf("%d",&reserva[i].cpf);
									
										           printf("Telefone para contato (sem pontuacao): ");
										           scanf("%d",&reserva[i].telefone);
								
										           printf("Quantidade de pessoas por mesa (2 a 8 pessoas): ");
									               scanf("%d",&reserva[i].qtdpes);
										           
                                                           while(reserva[i].qtdpes<2||reserva[i].qtdpes>8){
                                                                                                      
                                                                       printf("Quantidade incorreta. Reservas de 2 a 8 pessoas. Digite novamene: ");
                                                                       scanf("%d",&reserva[i].qtdpes);
                                                                                                      
                                                           }//while para quantidade de pessoas
									
										           printf("Mes (de 1 a 12): ");
										           scanf("%d",&reserva[i].mes);
										           
                                                           while(reserva[i].mes<1||reserva[i].mes>12){
                                                                                                      
                                                                       printf("Erro. Mes inexistente. Digite novamente: ");
                                                                       scanf("%d",&reserva[i].mes);
                                                                                                      
                                                           }//while para mes inexistente
                                                           
                                                   printf("Dia: ");
		                                           scanf("%d",&reserva[i].dia);
		                                           
                                                        
                                                                       
                                                            if(reserva[i].mes==4||reserva[i].mes==6||reserva[i].mes==9||reserva[i].mes==11){
                                                                                  
                                                                            while(reserva[i].dia<=0||reserva[i].dia>=31){
                                                                                                    
                                                                                    printf("Erro. Para o mes %d nao existe o dia %d. Digite novamente: ",reserva[i].mes,reserva[i].dia);
                                                                                    scanf("%d",&reserva[i].dia);
                                                                                                    
                                                                            }//while para dia 31
                                                                                            
                                                            }else if(reserva[i].mes==2){
                                                                                            
                                                                            while(reserva[i].dia<=0||reserva[i].dia>=30){
                                                                                                                                       
                                                                                    printf("Erro. Para o mes %d nao existe o dia %d. Digite novamente: ",reserva[i].mes,reserva[i].dia);
                                                                                    scanf("%d",&reserva[i].dia);
                                                                                                    
                                                                            }//while para fev 29+
                                                                                                                        
                                                            }else{
                                                            	
                                                            				while(reserva[i].dia<=0||reserva[i].dia>=32){
                                                                                                                                       
                                                                                    printf("Erro. Para o mes %d nao existe o dia %d. Digite novamente: ",reserva[i].mes,reserva[i].dia);
                                                                                    scanf("%d",&reserva[i].dia);
                                                                                                    
                                                                            }//while outros meses
                                                                            
															}//if para dia incorretos
															
															system("cls");
															
															printf("Reserva alterada com sucesso.\n");
															
															break;
															
												default:
													
													system("cls");
													printf("Comando incorreto.\n");
													
													break;
															
										}//switch
									
									
								}//if
								
								 printf("\nDeseja alterar outra reserva?\n\n");
									       printf("Sim          1\n");
									       printf("Nao          2\n\n");
									       printf("Digite o comando correspondente: ");
									       scanf("%d",&n);
									       
									       while(n<1||n>2){
                                                           
                                                           system("cls");
                                                        
                                                        printf("Comando inexistente.\n");
                                                        printf("\nDeseja alterar outra reserva?\n\n");
									                    printf("Sim          1\n");
									                    printf("Nao          2\n\n");
									                    printf("Digite o comando correspondente: ");
									                    scanf("%d",&n);
									                    printf("\n");
									                    
									                    system("cls");
                                                        
                                           }//while alterar reserva comando errado.
                                           
                                           		if(n==2){
                                           			
                                           		system("cls");
                                           	
										   		printf("Reserva(s) alterada(s) com sucesso.\n\n");
										   		
										   		} 
							
								}//while alterar mais reservas
								
								break;
								
						case 3:
							
								n=1;
									
                              	while(n==1){
                              
                              	system("cls");
								
								printf("Digite o numero da mesa que deseja excluir a reserva: ");
								scanf("%d",&nn);
								
								i = nn-1;
								
								if(reserva[i].ativador!=1){
																		
									printf("\nNao ha reserva gravada neste numero.\n");
									
								}else{
									
									printf("\nReserva %d\n",nn);
									printf("\n%s\n",reserva[i].nome);
									printf("RG: %d\n",reserva[i].rg);
									printf("CPF: %d\n",reserva[i].cpf);
									printf("Telefone: %d\n",reserva[i].telefone);
									printf("%d pessoas por mesa\n",reserva[i].qtdpes);
									printf("Data: %d/%d\n",reserva[i].dia,reserva[i].mes);
									
									printf("\nConfirma a exclusao dessa reserva %s?\n\n",login);
									printf("Sim          1\n");
									printf("Nao          2\n\n");
									printf("Digite o comando correspondente: ");
									scanf("%d",&nn);
									
										switch(nn){
											
											case 1: 
											
											reserva[i].ativador=0;
											
											system("cls");
											
											printf("Reserva excluida com sucesso.\n");
											
											break;
											
											case 2:
												
											system("cls");
											
											printf("Reserva nao foi excluida.\n");
											
											break;
											
											default:
											
											system("cls");
											
											printf("Comando incorreto\n");
											
											break;
										}
											
								}
								
								printf("\nDeseja excluir outra reserva?\n\n");
									       printf("Sim          1\n");
									       printf("Nao          2\n\n");
									       printf("Digite o comando correspondente: ");
									       scanf("%d",&n);
									       
									       while(n<1||n>2){
                                                           
                                                           system("cls");
                                                        
                                                        printf("Comando inexistente.\n");
                                                        printf("\nDeseja excluir outra reserva?\n\n");
									                    printf("Sim          1\n");
									                    printf("Nao          2\n\n");
									                    printf("Digite o comando correspondente: ");
									                    scanf("%d",&n);
									                    printf("\n");
									                    
									                    system("cls");
                                                        
                                           }//while excluir reserva comando errado.
                                           
                                           		if(n==2){
                                           			
                                           		system("cls");
                                           	
										   		printf("Reserva(s) excluida(s) com sucesso.\n\n");
										   		
										   		} 
									
								}//while exluir mais reservas
 
 								break;
								
						case 4:
								
								system("cls");
								
								printf("Tem certeza que deseja excluir todas as reservas %s?\n\n",login);
								printf("Sim          1\n");
								printf("Nao          2\n\n");
								printf("Digite o comando correspondente: ");
								scanf("%d",&n);
								
								switch(n){
									
									case 1:
										
										for(i=0;i<30;i++){
											
											reserva[i].ativador=0;	
											
										}
										
										system("cls");
										
										printf("Reserva(s) excluida(s) com sucesso.\n\n");
										
										break;
										
										case 2:
											
										system("cls");
											
										printf("As reservas nao foram excluidas.\n\n");
										
										break;
										
										default:
											
										system("cls");
										
										printf("Comando inexistente.\n\n");
										
										break;
										
								}//switch exclusao geral
								
								break;
								
						case 5:
							
								n=1;
									
                              		while(n==1){
                              
                              		system("cls");
								
									printf("Digite o numero da mesa que visualizar a reserva: ");
									scanf("%d",&nn);
								
									i = nn-1;
								
									if(reserva[i].ativador!=1){
																		
										printf("\nNao ha reserva gravada neste numero.\n\n");
									
									}else{
										
										printf("\nReserva %d\n",nn);
										printf("\n%s\n",reserva[i].nome);
										printf("RG: %d\n",reserva[i].rg);
										printf("CPF: %d\n",reserva[i].cpf);
										printf("Telefone: %d\n",reserva[i].telefone);
										printf("%d pessoas por mesa\n",reserva[i].qtdpes);
										printf("Data: %d/%d\n\n",reserva[i].dia,reserva[i].mes);
										
									}
									
									printf("Deseja visualizar outra reserva?\n\n");
									printf("Sim          1\n");
									printf("Nao          2\n\n");
									printf("Digite o comando correspondente: ");
									scanf("%d",&n);
									       
									    while(n<1||n>2){
                                                           
                                                        system("cls");
                                                        
                                                        printf("Comando inexistente.\n\n");
                                                        printf("Deseja Visualizar outra reserva?\n\n");
									                    printf("Sim          1\n");
									                    printf("Nao          2\n\n");
									                    printf("Digite o comando correspondente: ");
									                    scanf("%d",&n);
									                    printf("\n");
									                    
									                    system("cls");
									    }

								}
								system("cls");
								
								break;
								
						case 6:
							
								n=1;
								
									
                           		while(n==1){
                           		
                           		system("cls");
								
								if(n==1){
										
										cont=0;
										
										for(i=0;i<30;i++){
											
											if(reserva[i].ativador==1){
											
											nn=i+1;
											
											printf("Reserva %d\n",nn);
											printf("\n%s\n",reserva[i].nome);
											printf("RG: %d\n",reserva[i].rg);
											printf("CPF: %d\n",reserva[i].cpf);
											printf("Telefone: %d\n",reserva[i].telefone);
											printf("%d pessoas por mesa\n",reserva[i].qtdpes);
											printf("Data: %d/%d\n\n",reserva[i].dia,reserva[i].mes);
											printf("-----------------------------------\n\n");
											
											cont++;
											
											}
											
										}
									}
									
									printf("Total de %d reservas.\n\n",cont);
										
									printf("Deseja visualizar todas reservas novamente?\n\n");
									printf("Sim          1\n");
									printf("Nao          2\n\n");
									printf("Digite o comando correspondente: ");
									scanf("%d",&n);
									       
									    while(n<1||n>2){
                                                           
                                                        system("cls");
                                                        
                                                        printf("Comando inexistente.\n\n");
                                                        printf("Deseja Visualizar todas reservas novamente?\n\n");
									                    printf("Sim          1\n");
									                    printf("Nao          2\n\n");
									                    printf("Digite o comando correspondente: ");
									                    scanf("%d",&n);
									                    printf("\n");
									                    
									                    system("cls");
									    }

								}
								
								system("cls");
								
								break;
								
								default:
									
									system("cls");
									
									printf("Comando incorreto.\n\n");
									
									break;
										
                              }//switch do menu
    
    printf("O que deseja fazer %s?\n", login);	
	menu();
	scanf("%d",&menuop);
 }//menu
 
 	pont_arq=fopen("Reservas.txt", "w");
 	
 		for(i=0;i<30;i++){
 			
 			if(reserva[i].ativador==1){
 				
 				fprintf(pont_arq,"%s@%d@%d@%d@%d@%d@%d@%d\n", reserva[i].nome, reserva[i].rg, reserva[i].cpf, reserva[i].telefone, reserva[i].qtdpes, reserva[i].mes, reserva[i].dia, reserva[i].ativador);
			 
			 }else{
			 	
			 	fprintf(pont_arq,"0@0@0@0@0@0@0@0\n");
			 	
			 }
		 }
		 
	fclose(pont_arq);
            
}//main
