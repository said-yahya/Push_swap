NAME        = push_swap
BONUS_NAME  = checker

MANDATORY_DIR = Mandatory
BONUS_DIR     = Bonus

all:
	@$(MAKE) -C $(MANDATORY_DIR)
	@cp $(MANDATORY_DIR)/$(NAME) .

bonus:
	@$(MAKE) -C $(BONUS_DIR) bonus
	@cp $(BONUS_DIR)/$(BONUS_NAME) .

clean:
	@$(MAKE) -C $(MANDATORY_DIR) clean
	@$(MAKE) -C $(BONUS_DIR) clean

fclean:
	@$(MAKE) -C $(MANDATORY_DIR) fclean
	@$(MAKE) -C $(BONUS_DIR) fclean
	@rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re