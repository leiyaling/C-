package com.controller;

import java.util.List;
import javax.annotation.Resource;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import com.bean.Catalog;
import com.dao.CatalogDao;
import com.service.CatalogService;

@Controller
public class CatalogController {

	@Resource(name="catalogService")
	CatalogService catalogService;
	
	@RequestMapping("index")
	public String selectCatalog(Model model){
		List<Catalog> catalogList=catalogService.selectCatalog();
		model.addAttribute("catalogList", catalogList);
		return "index";
	}
	
	@RequestMapping("addCatalogView")
	public String addCatalogView(){
		return "add_catalog";
	}
	
	@RequestMapping("addCatalog")
	public String addCatalog(Catalog catalog,Model model){
		int k=catalogService.addCatalog(catalog);
		if(k==1){
			return "redirect:index";
		}else{
			model.addAttribute("msg", "添加图书类失败");
			return "fail";
		}
	}
	
	@RequestMapping("updateCatalogView")
	public String updateCatalogView(int catalogid,Model model){
		Catalog catalog=catalogService.selectCatalogByCatalogId(catalogid);
		model.addAttribute("catalog", catalog);
		return "update_catalog";
	}
	
	@RequestMapping("updateCatalog")
	public String updateCatalog(Catalog catalog,Model model){
		int k=catalogService.updateCatalog(catalog);
		if(k==1){
			return "redirect:index";
		}else{
			model.addAttribute("msg", "修改图书类失败");
			return "fail";
		}
	}
	
	@RequestMapping("deleteCatalog")
	public String deleteCatalog(int catalogid,Model model){
		int k=catalogService.deleteCatalog(catalogid);
		if(k==1){
			return "redirect:index";
		}else{
			model.addAttribute("msg", "删除图书类失败");
			return "fail";
		}
	}
}
