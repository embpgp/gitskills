# product-specs.mk  
  
## 逐个加载PRODUCT_SPECS指定的mk文。提供一种可定制化产品信息的方法  
$(foreach specfile, $(PRODUCT_SPECS), $(eval -include $(specfile))) 
